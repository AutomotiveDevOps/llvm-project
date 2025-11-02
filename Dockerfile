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
ENV INSTALL_DIR=/build/install
ENV PACKAGE_DIR=/build/packages

# Create directories
RUN mkdir -p ${BUILD_DIR} ${INSTALL_DIR} ${PACKAGE_DIR}

# Configure and build LLVM/Clang with PowerPC e200 VLE support
WORKDIR ${BUILD_DIR}

RUN cmake -G Ninja \
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
    -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
    -DLLVM_DEFAULT_TARGET_TRIPLE=powerpc-none-elf \
    /build/src/llvm

# Build with parallel jobs (use all available CPUs)
RUN ninja -j$(nproc)

# Install to install directory
RUN ninja install

# Prepare package metadata
WORKDIR ${PACKAGE_DIR}

# Get LLVM version for package naming (read from source if available, otherwise use default)
RUN if [ -f /build/src/llvm/CMakeLists.txt ]; then \
        LLVM_VERSION=$(grep "set(LLVM_VERSION_MAJOR" /build/src/llvm/CMakeLists.txt | head -1 | sed 's/.*LLVM_VERSION_MAJOR *\([0-9]*\).*/\1/' || echo "11") && \
        LLVM_MINOR=$(grep "set(LLVM_VERSION_MINOR" /build/src/llvm/CMakeLists.txt | head -1 | sed 's/.*LLVM_VERSION_MINOR *\([0-9]*\).*/\1/' || echo "0") && \
        LLVM_PATCH=$(grep "set(LLVM_VERSION_PATCH" /build/src/llvm/CMakeLists.txt | head -1 | sed 's/.*LLVM_VERSION_PATCH *\([0-9]*\).*/\1/' || echo "0") && \
        PACKAGE_VERSION="${LLVM_VERSION}.${LLVM_MINOR}.${LLVM_PATCH}"; \
    else \
        PACKAGE_VERSION="11.0.0"; \
    fi && \
    PACKAGE_NAME="llvm-ppc-vle-${PACKAGE_VERSION}" && \
    echo "${PACKAGE_VERSION}" > /tmp/llvm_version.txt && \
    echo "${PACKAGE_NAME}" > /tmp/pkg_name.txt && \
    echo "Package version: ${PACKAGE_VERSION}, Name: ${PACKAGE_NAME}"

# Determine build architecture (for .deb package)
RUN BUILD_ARCH=$(dpkg-architecture -qDEB_BUILD_ARCH) && echo "${BUILD_ARCH}" > /tmp/build_arch.txt

# Create .deb package
RUN PACKAGE_VERSION=$(cat /tmp/llvm_version.txt) && \
    PACKAGE_NAME=$(cat /tmp/pkg_name.txt) && \
    BUILD_ARCH=$(cat /tmp/build_arch.txt) && \
    DEB_DIR=${PACKAGE_DIR}/${PACKAGE_NAME} && \
    mkdir -p ${DEB_DIR}/DEBIAN && \
    mkdir -p ${DEB_DIR}/usr && \
    cp -r ${INSTALL_DIR}/* ${DEB_DIR}/usr/ && \
    printf 'Package: llvm-ppc-vle\nVersion: %s\nArchitecture: %s\nMaintainer: LLVM PowerPC e200 VLE Build\nDescription: LLVM/Clang toolchain for PowerPC Embedded with VLE extensions\n This package contains the complete LLVM/Clang toolchain built for\n PowerPC e200 cores with Variable Length Encoding (VLE) support.\n Includes clang, lld, compiler-rt, and all necessary libraries and headers\n for compiling embedded PowerPC code with VLE instructions.\nSection: devel\nPriority: optional\n' "${PACKAGE_VERSION}" "${BUILD_ARCH}" > ${DEB_DIR}/DEBIAN/control && \
    dpkg-deb --build ${DEB_DIR} ${PACKAGE_DIR}/${PACKAGE_NAME}.deb && \
    echo "Created ${PACKAGE_NAME}.deb"

# Create .tar.bz2 archive
RUN PACKAGE_NAME=$(cat /tmp/pkg_name.txt) && \
    cd ${INSTALL_DIR} && \
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

