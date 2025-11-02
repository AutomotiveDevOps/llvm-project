# -*- Python -*-

# Configuration file for the 'lit' test runner.

import os
import sys
import re
import platform
import subprocess

import lit.util
import lit.formats
from lit.llvm import llvm_config
from lit.llvm.subst import FindTool
from lit.llvm.subst import ToolSubst

# name: The name of this test suite.
config.name = 'LLVM'

# TODO: Consolidate the logic for turning on the internal shell by default for all LLVM test suites.
# See https://github.com/llvm/llvm-project/issues/106636 for more details.
#
# We prefer the lit internal shell which provides a better user experience on failures
# and is faster unless the user explicitly disables it with LIT_USE_INTERNAL_SHELL=0
# env var.
use_lit_shell = True
lit_shell_env = os.environ.get('LIT_USE_INTERNAL_SHELL')
if lit_shell_env:
    use_lit_shell = lit.util.pythonize_bool(lit_shell_env)

# testFormat: The test format to use to interpret tests.
extra_substitutions = []
if getattr(config, 'enable_profcheck', False):
    extra_substitutions = [
        (r'FileCheck .*', 'cat > /dev/null'),
        (r'not FileCheck .*', 'cat > /dev/null'),
    ]
config.test_format = lit.formats.ShTest(not use_lit_shell, extra_substitutions)

# suffixes: A list of file extensions to treat as test files. This is overriden
# by individual lit.local.cfg files in the test subdirectories.
config.suffixes = ['.ll', '.c', '.cxx', '.test', '.txt', '.s', '.mir']

# excludes: A list of directories to exclude from the testsuite. The 'Inputs'
# subdirectories contain auxiliary inputs for various tests in their parent
# directories.
config.excludes = ['Inputs', 'CMakeLists.txt', 'README.txt', 'LICENSE.txt']

# test_source_root: The root path where tests are located.
config.test_source_root = os.path.dirname(__file__)

# test_exec_root: The root path where tests should be run.
if hasattr(config, 'llvm_obj_root'):
    config.test_exec_root = os.path.join(config.llvm_obj_root, 'test')
else:
    config.test_exec_root = config.test_source_root

# Tweak the PATH to include the tools dir.
if llvm_config and hasattr(config, 'llvm_tools_dir'):
    llvm_config.with_environment('PATH', config.llvm_tools_dir, append_path=True)

# Propagate some variables from the host environment.
if llvm_config:
    llvm_config.with_system_environment(
        ['HOME', 'INCLUDE', 'LIB', 'TMP', 'TEMP', 'ASAN_SYMBOLIZER_PATH', 'MSAN_SYMBOLIZER_PATH'])


# Set up OCAMLPATH to include newly built OCaml libraries.
if llvm_config and hasattr(config, 'llvm_lib_dir'):
    top_ocaml_lib = os.path.join(config.llvm_lib_dir, 'ocaml')
    llvm_ocaml_lib = os.path.join(top_ocaml_lib, 'llvm')

    llvm_config.with_system_environment('OCAMLPATH')
    llvm_config.with_environment('OCAMLPATH', top_ocaml_lib, append_path=True)
    llvm_config.with_environment('OCAMLPATH', llvm_ocaml_lib, append_path=True)

    llvm_config.with_system_environment('CAML_LD_LIBRARY_PATH')
    llvm_config.with_environment(
        'CAML_LD_LIBRARY_PATH', llvm_ocaml_lib, append_path=True)

    # Set up OCAMLRUNPARAM to enable backtraces in OCaml tests.
    llvm_config.with_environment('OCAMLRUNPARAM', 'b')

# Provide the path to asan runtime lib 'libclang_rt.asan_osx_dynamic.dylib' if
# available. This is darwin specific since it's currently only needed on darwin.


def get_asan_rtlib():
    if not hasattr(config, 'llvm_use_sanitizer') or not 'Address' in config.llvm_use_sanitizer or \
       not hasattr(config, 'host_os') or not 'Darwin' in config.host_os or \
       not hasattr(config, 'host_triple') or not 'x86' in config.host_triple:
        return ''
    try:
        import glob
    except:
        print('glob module not found, skipping get_asan_rtlib() lookup')
        return ''
    # The libclang_rt.asan_osx_dynamic.dylib path is obtained using the relative
    # path from the host cc.
    if not hasattr(config, 'host_cc'):
        return ''
    host_lib_dir = os.path.join(os.path.dirname(config.host_cc), '../lib')
    asan_dylib_dir_pattern = host_lib_dir + \
        '/clang/*/lib/darwin/libclang_rt.asan_osx_dynamic.dylib'
    found_dylibs = glob.glob(asan_dylib_dir_pattern)
    if len(found_dylibs) != 1:
        return ''
    return found_dylibs[0]


if llvm_config:
    llvm_config.use_default_substitutions()

# Add site-specific substitutions.
if hasattr(config, 'llvm_shlib_dir'):
    config.substitutions.append(('%llvmshlibdir', config.llvm_shlib_dir))
if hasattr(config, 'llvm_shlib_ext'):
    config.substitutions.append(('%shlibext', config.llvm_shlib_ext))
if hasattr(config, 'llvm_exe_ext'):
    config.substitutions.append(('%exeext', config.llvm_exe_ext))


lli_args = []
# The target triple used by default by lli is the process target triple (some
# triple appropriate for generating code for the current process) but because
# we don't support COFF in MCJIT well enough for the tests, force ELF format on
# Windows.  FIXME: the process target triple should be used here, but this is
# difficult to obtain on Windows.
if hasattr(config, 'host_triple') and re.search(r'cygwin|windows-gnu|windows-msvc', config.host_triple):
    lli_args = ['-mtriple=' + config.host_triple + '-elf']

llc_args = []

# Similarly, have a macro to use llc with DWARF even when the host is Windows
if hasattr(config, 'target_triple') and re.search(r'windows-msvc', config.target_triple):
    llc_args = [' -mtriple=' +
                config.target_triple.replace('-msvc', '-gnu')]

# Provide the path to asan runtime lib if available. On darwin, this lib needs
# to be loaded via DYLD_INSERT_LIBRARIES before libLTO.dylib in case the files
# to be linked contain instrumented sanitizer code.
ld64_cmd = getattr(config, 'ld64_executable', '')
asan_rtlib = get_asan_rtlib()
if asan_rtlib:
    ld64_cmd = 'DYLD_INSERT_LIBRARIES={} {}'.format(asan_rtlib, ld64_cmd)

if hasattr(config, 'ocamlfind_executable') and hasattr(config, 'llvm_lib_dir') and hasattr(config, 'ocaml_flags'):
    ocamlc_command = '%s ocamlc -cclib -L%s %s' % (
        config.ocamlfind_executable, config.llvm_lib_dir, config.ocaml_flags)
    ocamlopt_command = 'true'
    if getattr(config, 'have_ocamlopt', False):
        ocamlopt_command = '%s ocamlopt -cclib -L%s -cclib -Wl,-rpath,%s %s' % (
            config.ocamlfind_executable, config.llvm_lib_dir, config.llvm_lib_dir, config.ocaml_flags)
else:
    ocamlc_command = 'true'
    ocamlopt_command = 'true'

opt_viewer_cmd = '%s %s/tools/opt-viewer/opt-viewer.py' % (sys.executable, getattr(config, 'llvm_src_root', os.path.dirname(os.path.dirname(os.path.dirname(__file__)))))

if hasattr(config, 'llvm_tools_dir'):
    llvm_locstats_tool = os.path.join(config.llvm_tools_dir, 'llvm-locstats')
    config.substitutions.append(
        ('%llvm-locstats', "'%s' %s" % (getattr(config, 'python_executable', sys.executable), llvm_locstats_tool)))
    config.llvm_locstats_used = os.path.exists(llvm_locstats_tool)
else:
    config.llvm_locstats_used = False

tools = [
    ToolSubst('%lli', FindTool('lli'), post='.', extra_args=lli_args),
    ToolSubst('%llc_dwarf', FindTool('llc'), extra_args=llc_args),
    ToolSubst('%go', getattr(config, 'go_executable', ''), unresolved='ignore'),
    ToolSubst('%gold', getattr(config, 'gold_executable', ''), unresolved='ignore'),
    ToolSubst('%ld64', ld64_cmd, unresolved='ignore'),
    ToolSubst('%ocamlc', ocamlc_command, unresolved='ignore'),
    ToolSubst('%ocamlopt', ocamlopt_command, unresolved='ignore'),
    ToolSubst('%opt-viewer', opt_viewer_cmd),
    ToolSubst('%llvm-objcopy', FindTool('llvm-objcopy')),
    ToolSubst('%llvm-strip', FindTool('llvm-strip')),
    ToolSubst('%llvm-install-name-tool', FindTool('llvm-install-name-tool')),
]

# FIXME: Why do we have both `lli` and `%lli` that do slightly different things?
tools.extend([
    'dsymutil', 'lli', 'lli-child-target', 'llvm-ar', 'llvm-as',
    'llvm-addr2line', 'llvm-bcanalyzer', 'llvm-config', 'llvm-cov',
    'llvm-cxxdump', 'llvm-cvtres', 'llvm-diff', 'llvm-dis', 'llvm-dwarfdump',
    'llvm-exegesis', 'llvm-extract', 'llvm-isel-fuzzer', 'llvm-ifs',
    'llvm-install-name-tool', 'llvm-jitlink', 'llvm-opt-fuzzer', 'llvm-lib',
    'llvm-link', 'llvm-lto', 'llvm-lto2', 'llvm-mc', 'llvm-mca',
    'llvm-modextract', 'llvm-nm', 'llvm-objcopy', 'llvm-objdump',
    'llvm-pdbutil', 'llvm-profdata', 'llvm-ranlib', 'llvm-rc', 'llvm-readelf',
    'llvm-readobj', 'llvm-rtdyld', 'llvm-size', 'llvm-split', 'llvm-strings',
    'llvm-strip', 'llvm-tblgen', 'llvm-undname', 'llvm-c-test', 'llvm-cxxfilt',
    'llvm-xray', 'yaml2obj', 'obj2yaml', 'yaml-bench', 'verify-uselistorder',
    'bugpoint', 'llc', 'llvm-symbolizer', 'opt', 'sancov', 'sanstats'])

# The following tools are optional
tools.extend([
    ToolSubst('llvm-go', unresolved='ignore'),
    ToolSubst('llvm-mt', unresolved='ignore'),
    ToolSubst('Kaleidoscope-Ch3', unresolved='ignore'),
    ToolSubst('Kaleidoscope-Ch4', unresolved='ignore'),
    ToolSubst('Kaleidoscope-Ch5', unresolved='ignore'),
    ToolSubst('Kaleidoscope-Ch6', unresolved='ignore'),
    ToolSubst('Kaleidoscope-Ch7', unresolved='ignore'),
    ToolSubst('Kaleidoscope-Ch8', unresolved='ignore')])

if llvm_config and hasattr(config, 'llvm_tools_dir'):
    llvm_config.add_tool_substitutions(tools, config.llvm_tools_dir)

# Targets

if hasattr(config, 'targets_to_build'):
    config.targets = frozenset(config.targets_to_build.split())
    for arch in config.targets_to_build.split():
        config.available_features.add(arch.lower() + '-registered-target')
else:
    config.targets = frozenset()

# Features
known_arches = ["x86_64", "mips64", "ppc64", "aarch64"]
if (hasattr(config, 'host_ldflags') and hasattr(config, 'llvm_host_triple')
    and config.host_ldflags.find("-m32") < 0
    and any(config.llvm_host_triple.startswith(x) for x in known_arches)):
    config.available_features.add("llvm-64-bits")

config.available_features.add("host-byteorder-" + sys.byteorder + "-endian")

if sys.platform in ['win32']:
    # ExecutionEngine, no weak symbols in COFF.
    config.available_features.add('uses_COFF')
else:
    # Others/can-execute.txt
    config.available_features.add('can-execute')

# Loadable module
if getattr(config, 'has_plugins', False):
    config.available_features.add('plugins')

if getattr(config, 'build_examples', False):
    config.available_features.add('examples')

if getattr(config, 'linked_bye_extension', False):
    config.substitutions.append(('%llvmcheckext', 'CHECK-EXT'))
    config.substitutions.append(('%loadbye', ''))
    config.substitutions.append(('%loadnewpmbye', ''))
else:
    config.substitutions.append(('%llvmcheckext', 'CHECK-NOEXT'))
    if hasattr(config, 'llvm_shlib_dir') and hasattr(config, 'llvm_shlib_ext'):
        config.substitutions.append(('%loadbye',
                                     '-load={}/Bye{}'.format(config.llvm_shlib_dir,
                                                             config.llvm_shlib_ext)))
        config.substitutions.append(('%loadnewpmbye',
                                     '-load-pass-plugin={}/Bye{}'
                                     .format(config.llvm_shlib_dir,
                                             config.llvm_shlib_ext)))
    else:
        config.substitutions.append(('%loadbye', ''))
        config.substitutions.append(('%loadnewpmbye', ''))


# Static libraries are not built if BUILD_SHARED_LIBS is ON.
if not getattr(config, 'build_shared_libs', True) and not getattr(config, 'link_llvm_dylib', False):
    config.available_features.add('static-libs')

def have_cxx_shared_library():
    if not hasattr(config, 'llvm_tools_dir'):
        return False
    readobj_exe = lit.util.which('llvm-readobj', config.llvm_tools_dir)
    if not readobj_exe:
        print('llvm-readobj not found')
        return False

    try:
        readobj_cmd = subprocess.Popen(
            [readobj_exe, '-needed-libs', readobj_exe], stdout=subprocess.PIPE)
    except OSError:
        print('could not exec llvm-readobj')
        return False

    readobj_out = readobj_cmd.stdout.read().decode('ascii')
    readobj_cmd.wait()

    regex = re.compile(r'(libc\+\+|libstdc\+\+|msvcp).*\.(so|dylib|dll)')
    needed_libs = False
    for line in readobj_out.splitlines():
        if 'NeededLibraries [' in line:
            needed_libs = True
        if ']' in line:
            needed_libs = False
        if needed_libs and regex.search(line.lower()):
            return True
    return False

if have_cxx_shared_library():
    config.available_features.add('cxx-shared-library')

if getattr(config, 'libcxx_used', False):
    config.available_features.add('libcxx-used')

# LLVM can be configured with an empty default triple
# Some tests are "generic" and require a valid default triple
if hasattr(config, 'target_triple') and config.target_triple:
    config.available_features.add('default_triple')

import subprocess


def have_ld_plugin_support():
    if not hasattr(config, 'llvm_shlib_dir') or not hasattr(config, 'llvm_shlib_ext'):
        return False
    if not os.path.exists(os.path.join(config.llvm_shlib_dir, 'LLVMgold' + config.llvm_shlib_ext)):
        return False

    gold_exe = getattr(config, 'gold_executable', None)
    if not gold_exe:
        return False
    ld_cmd = subprocess.Popen(
        [gold_exe, '--help'], stdout=subprocess.PIPE, env={'LANG': 'C'})
    ld_out = ld_cmd.stdout.read().decode()
    ld_cmd.wait()

    if not '-plugin' in ld_out:
        return False

    # check that the used emulations are supported.
    emu_line = [l for l in ld_out.split('\n') if 'supported emulations' in l]
    if len(emu_line) != 1:
        return False
    emu_line = emu_line[0]
    fields = emu_line.split(':')
    if len(fields) != 3:
        return False
    emulations = fields[2].split()
    if 'elf_x86_64' not in emulations:
        return False
    if 'elf32ppc' in emulations:
        config.available_features.add('ld_emu_elf32ppc')

    ld_version = subprocess.Popen(
        [gold_exe, '--version'], stdout=subprocess.PIPE, env={'LANG': 'C'})
    if not 'GNU gold' in ld_version.stdout.read().decode():
        return False
    ld_version.wait()

    return True


if have_ld_plugin_support():
    config.available_features.add('ld_plugin')


def have_ld64_plugin_support():
    if not hasattr(config, 'llvm_shlib_dir') or not hasattr(config, 'llvm_shlib_ext'):
        return False
    if not os.path.exists(os.path.join(config.llvm_shlib_dir, 'libLTO' + config.llvm_shlib_ext)):
        return False

    if config.ld64_executable == '':
        return False

    ld_cmd = subprocess.Popen(
        [config.ld64_executable, '-v'], stderr=subprocess.PIPE)
    ld_out = ld_cmd.stderr.read().decode()
    ld_cmd.wait()

    if 'ld64' not in ld_out or 'LTO' not in ld_out:
        return False

    return True


if have_ld64_plugin_support():
    config.available_features.add('ld64_plugin')

# Ask llvm-config about asserts and global-isel.
if llvm_config:
    llvm_config.feature_config(
        [('--assertion-mode', {'ON': 'asserts'}),
         ('--has-global-isel', {'ON': 'global-isel'})])

if 'darwin' == sys.platform:
    cmd = ['sysctl', 'hw.optional.fma']
    sysctl_cmd = subprocess.Popen(cmd, stdout=subprocess.PIPE)

    # Non zero return, probably a permission issue
    if sysctl_cmd.wait():
        print(
          "Warning: sysctl exists but calling \"{}\" failed, defaulting to no fma3.".format(
          " ".join(cmd)))
    else:
        result = sysctl_cmd.stdout.read().decode('ascii')
        if 'hw.optional.fma: 1' in result:
            config.available_features.add('fma3')

# .debug_frame is not emitted for targeting Windows x64.
if hasattr(config, 'target_triple') and not re.match(r'^x86_64.*-(windows-gnu|windows-msvc)', config.target_triple):
    config.available_features.add('debug_frame')

if getattr(config, 'have_libxar', False):
    config.available_features.add('xar')

if getattr(config, 'enable_threads', False):
    config.available_features.add('thread_support')

if getattr(config, 'llvm_libxml2_enabled', False):
    config.available_features.add('libxml2')

if getattr(config, 'have_opt_viewer_modules', False):
    config.available_features.add('have_opt_viewer_modules')
