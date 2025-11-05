# Cursor Rules for LLVM Project

## Build Validation Rule

**Every 20 commits MUST be accompanied by a build in build-new by running build.sh. This ensures that all changes are not breaking.**

### Implementation Details

- After every 20 commits, the build must be validated by running `build-new/build.sh`
- This rule helps catch breaking changes early and ensures the codebase remains in a buildable state
- The build should be performed from the project root directory: `/projects/vle/llvm-project2`
- Build failures should be addressed before continuing with additional commits

### Build Command

```bash
cd /projects/vle/llvm-project2
./build-new/build.sh
```

