[![Build Status](https://jenkins.plange.tech/job/coder0xff/job/Plange/job/master/badge/icon)](https://jenkins.plange.tech/job/coder0xff/job/Plange/job/master/)

For documentation, see the [plange.tech](http://plange.tech) website, which is a clone of this repository.

## Notation
 * `SOURCE`: the directory containing the cloned source code
 * `BUILD`: the directory for intermediate build files
 * `INSTALL`: the directory for build output files

## Building
C++17 features are used liberally, and a capable compiler and build tools are required. Linux and Windows are currently supported. Successful compilation on other platforms is incidental, but may be officially supported in the future. Let us know if you get it working somewhere.

#### Prerequisites
 * An internet connection for downloading external dependencies
 * [Git](https://git-scm.com)
 * [CMake 3.10 or newer](https://cmake.org/download/)
 * Either:
   * gcc 7
   * Microsoft Visual C++ 2017
 * Either:
   * [Python 2.x](https://www.python.org/downloads/) (On Windows, choose to update the %PATH% environment variable during installation.)
   * [LLVM 6](https://github.com/llvm-mirror/llvm)
 * Optional: yaml-cpp
 
#### Build
 * Clone the repository to a directory of your choice, `SOURCE`.
 * Create a directory for build files, `BUILD`
 * Run cmake
 ```
    cd BUILD
    cmake SOURCE
    cmake --build .
 ```
 
### Caveats
 * The Ubuntu 16 LTS package `libyaml-cpp-dev` has an undeclared dependency on `libboost-all-dev` and may cause build to fail with fatal `error: boost/shared_ptr.hpp: No such file or directory`. You may:
   * Install boost `sudo apt install libboost-all-dev`, or
   * Uninstall the faulty yaml-cpp package `sudo apt remove libyaml-cpp-dev`, or
   * Modify the CMakeLists.txt files to force an external project in the super build
     * ./CMakeLists.txt
     * ./source/grammar_gen/CMakeLists.txt
 * In-source builds are not supported, but may work incidentally. Out-of-source builds (where `SOURCE` and `BUILD` are different directories) are recommended.
 * Python is only required if LLVM must be built, or to use miscellaneous python programs within this repository

### Notes
 * During the first build:
   * If an installation of LLVM 6 is not found it will be downloaded and built automatically. It will take some time.
   * If an installation of yaml-cpp is not found it will be downloaded and built automatically.
   * Google test will be downloaded and built automatically.
 * The top level CMakeLists.txt is a CMake "super build" for preparing dependencies.
   * Plange source code resides in `SOURCE/source` directory as a separate CMake project.
   * Plange build files reside in `BUILD/prefix/src/plange-build` and may be built directly once the super build completes
 * Downloaded dependencies will be stored in `BUILD/Downloads` and may be deleted once building completes
 * Built dependencies will be stored in `BUILD/Dependencies`
 
#### Working with Visual Studio .sln files
On Windows, building will generate `BUILD/project.sln`, and `BUILD/prefix/src/plange-build/plange.sln`. They may be opened in Visual Studio 2017 or later. The first solution corresponds to the super build, which need be built only once. Afterwords, the second solution can be used for working with the source code.
