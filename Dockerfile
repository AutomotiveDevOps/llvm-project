# Dockerfile for building LLVM/Clang with PowerPC e200 VLE support
# Target: Ubuntu 24.04
# Output: .deb package and .tar.bz2 archive

FROM ubuntu:24.04

LABEL maintainer="LLVM PowerPC e200 VLE Build"
LABEL description="Build LLVM/Clang toolchain for PowerPC Embedded with VLE extensions"

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    git \
    python3 \
    python3-pip \
    zlib1g-dev \
    libncurses5-dev \
    libncursesw5-dev \
    libzstd-dev \
    libxml2-dev \
    liblzma-dev \
    libedit-dev \
    libbsd-dev \
    pkg-config \
    dpkg-dev \
    fakeroot \
    bzip2 \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /build

# Copy source code (assumes source is mounted or copied)
COPY . /build/src

# Build configuration
ENV BUILD_DIR=/build/build
ENV PACKAGE_DIR=/build/packages

# Set parallel build level to use all available CPUs
# Detect CPU count and store it for use during build
# CMAKE_BUILD_PARALLEL_LEVEL can also be set via environment, but we'll pass it explicitly to ninja
RUN echo "Available CPUs: $(nproc)" && \
    echo "$(nproc)" > /tmp/cpu_count.txt

# Get LLVM version for package naming and install path (extract early)
RUN if [ -f /build/src/cmake/Modules/LLVMVersion.cmake ]; then \
        LLVM_VERSION=$(grep "^  set(LLVM_VERSION_MAJOR" /build/src/cmake/Modules/LLVMVersion.cmake | head -1 | sed 's/.*LLVM_VERSION_MAJOR *\([0-9]*\).*/\1/' || echo "22") && \
        LLVM_MINOR=$(grep "^  set(LLVM_VERSION_MINOR" /build/src/cmake/Modules/LLVMVersion.cmake | head -1 | sed 's/.*LLVM_VERSION_MINOR *\([0-9]*\).*/\1/' || echo "0") && \
        LLVM_PATCH=$(grep "^  set(LLVM_VERSION_PATCH" /build/src/cmake/Modules/LLVMVersion.cmake | head -1 | sed 's/.*LLVM_VERSION_PATCH *\([0-9]*\).*/\1/' || echo "0") && \
        PACKAGE_VERSION="${LLVM_VERSION}.${LLVM_MINOR}.${LLVM_PATCH}"; \
    else \
        PACKAGE_VERSION="22.0.0"; \
    fi && \
    INSTALL_PATH="/usr/local/powerpc-eabivle-llvm-${PACKAGE_VERSION}" && \
    PACKAGE_NAME="powerpc-eabivle-llvm-${PACKAGE_VERSION}" && \
    echo "${PACKAGE_VERSION}" > /tmp/llvm_version.txt && \
    echo "${PACKAGE_NAME}" > /tmp/pkg_name.txt && \
    echo "${INSTALL_PATH}" > /tmp/install_path.txt && \
    echo "Package version: ${PACKAGE_VERSION}, Name: ${PACKAGE_NAME}, Install path: ${INSTALL_PATH}"

# Create directories
RUN mkdir -p ${BUILD_DIR} ${PACKAGE_DIR} && \
    INSTALL_PATH=$(cat /tmp/install_path.txt) && \
    mkdir -p $(dirname ${INSTALL_PATH})

# Configure and build LLVM/Clang with PowerPC e200 VLE support
WORKDIR ${BUILD_DIR}

RUN INSTALL_PATH=$(cat /tmp/install_path.txt) && \
    cmake -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_TARGETS_TO_BUILD="PowerPC" \
    -DLLVM_ENABLE_PROJECTS="clang;lld" \
    -DLLVM_ENABLE_ASSERTIONS=OFF \
    -DLLVM_ENABLE_BACKTRACES=OFF \
    -DLLVM_ENABLE_EH=ON \
    -DLLVM_ENABLE_RTTI=ON \
    -DLLVM_INCLUDE_TESTS=OFF \
    -DLLVM_INCLUDE_DOCS=OFF \
    -DLLVM_INCLUDE_EXAMPLES=OFF \
    -DLLVM_INCLUDE_BENCHMARKS=OFF \
    -DCMAKE_INSTALL_PREFIX=${INSTALL_PATH} \
    -DLLVM_DEFAULT_TARGET_TRIPLE=powerpc-none-elf \
    /build/src/llvm

# Build with parallel jobs (use all available CPUs)
# Note: ninja auto-detects CPUs by default, but we make it explicit
RUN NPROC=$(cat /tmp/cpu_count.txt) && \
    echo "Building with ${NPROC} parallel jobs..." && \
    ninja -j${NPROC}

# Install to install directory (install is typically fast, but can also be parallelized)
RUN NPROC=$(cat /tmp/cpu_count.txt) && \
    ninja install -j${NPROC}

# Prepare package metadata
WORKDIR ${PACKAGE_DIR}

# Determine build architecture (for .deb package)
RUN BUILD_ARCH=$(dpkg-architecture -qDEB_BUILD_ARCH) && echo "${BUILD_ARCH}" > /tmp/build_arch.txt

# Create .deb package
RUN PACKAGE_VERSION=$(cat /tmp/llvm_version.txt) && \
    PACKAGE_NAME=$(cat /tmp/pkg_name.txt) && \
    INSTALL_PATH=$(cat /tmp/install_path.txt) && \
    BUILD_ARCH=$(cat /tmp/build_arch.txt) && \
    DEB_DIR=${PACKAGE_DIR}/${PACKAGE_NAME} && \
    mkdir -p ${DEB_DIR}/DEBIAN && \
    mkdir -p ${DEB_DIR}${INSTALL_PATH} && \
    cp -r ${INSTALL_PATH}/* ${DEB_DIR}${INSTALL_PATH}/ && \
    printf 'Package: powerpc-eabivle-llvm\nVersion: %s\nArchitecture: %s\nMaintainer: LLVM PowerPC e200 VLE Build\nDescription: LLVM/Clang toolchain for PowerPC Embedded with VLE extensions\n This package contains the complete LLVM/Clang toolchain built for\n PowerPC e200 cores with Variable Length Encoding (VLE) support.\n Installs to %s to avoid conflicts with system LLVM.\n Includes clang, lld, compiler-rt, and all necessary libraries and headers\n for compiling embedded PowerPC code with VLE instructions.\nSection: devel\nPriority: optional\n' "${PACKAGE_VERSION}" "${BUILD_ARCH}" "${INSTALL_PATH}" > ${DEB_DIR}/DEBIAN/control && \
    dpkg-deb --build ${DEB_DIR} ${PACKAGE_DIR}/${PACKAGE_NAME}.deb && \
    echo "Created ${PACKAGE_NAME}.deb (installs to ${INSTALL_PATH})"

# Create .tar.bz2 archive
RUN PACKAGE_NAME=$(cat /tmp/pkg_name.txt) && \
    INSTALL_PATH=$(cat /tmp/install_path.txt) && \
    cd ${INSTALL_PATH} && \
    tar -cjf ${PACKAGE_DIR}/${PACKAGE_NAME}.tar.bz2 . && \
    echo "Created ${PACKAGE_NAME}.tar.bz2"

# Set up entrypoint to copy files to output volume
WORKDIR ${PACKAGE_DIR}

# Create entrypoint script
RUN cat > /entrypoint.sh <<'EOF'
#!/bin/bash
set -e
PACKAGE_DIR=/build/packages
OUTPUT_DIR=/output
if [ -d "${OUTPUT_DIR}" ]; then
    echo "Copying packages to ${OUTPUT_DIR}..."
    cp ${PACKAGE_DIR}/*.deb ${OUTPUT_DIR}/ 2>/dev/null || true
    cp ${PACKAGE_DIR}/*.tar.bz2 ${OUTPUT_DIR}/ 2>/dev/null || true
    ls -lh ${OUTPUT_DIR}/
    echo "Packages ready in ${OUTPUT_DIR}/"
else
    echo "Output directory ${OUTPUT_DIR} not found. Listing built packages:"
    ls -lh ${PACKAGE_DIR}/
    echo ""
    echo "To get the packages, mount a volume to /output:"
    echo "  docker run -v \$(pwd)/output:/output <image>"
fi
EOF
RUN chmod +x /entrypoint.sh

# Default command: copy packages to output directory
ENTRYPOINT ["/entrypoint.sh"]

