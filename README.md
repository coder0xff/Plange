[![Build Status](https://jenkins.plange.tech/job/coder0xff/job/Plange/job/master/badge/icon)](https://jenkins.plange.tech/job/coder0xff/job/Plange/job/master/)

For documentation, see the [plange.tech](http://plange.tech) website, which is a clone of this repository.

## Notation
 * `SOURCE`: the directory containing the cloned source code
 * `BUILD`: the directory for intermediate build files

## Building
C++17 features are used liberally, and a capable compiler and build tools are required. Linux and Windows are currently supported. Successful compilation on other platforms is incidental, but may be officially supported in the future. Let us know if you get it working somewhere.

### Prerequisites
 * [CMake 3.10 or newer](https://cmake.org/download/)
 * [Python 2.x](https://www.python.org/downloads/) (On Windows, choose to update the %PATH% environment variable during installation.)
 * Either:
   * gcc 7
   * Microsoft Visual C++ 2017

### Build
 * Clone the repository to a directory of your choice, `SOURCE`.
 * Create a directory for build files, `BUILD`
 * Run cmake
 ```
    cd BUILD
    cmake SOURCE
    cmake --build .
 ```
 
### Caveats
 * In-source builds are not supported, but may work incidentally. Out-of-source builds (where `SOURCE` and `BUILD` are different directories) are recommended.
 * LLVM, LLD, yaml-cpp, and googletest are stored in git submodules, and will be downloaded by the configuration script if not already present. This may take some time.
