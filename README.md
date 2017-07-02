# Plange
A project to create a revolutionary development environment

For documentation, see the [plange.tech](http://plange.tech) website.

The instructions below use `./` to donate the location in which the plange source code has been downloaded/cloned to.

## Building
CMake is used to build Plange. C++17 support is required. Build has been tested on Visual Studio 2017, and gcc 7.

#### Prerequisites
 * [CMake 3.9 or newer](https://cmake.org/download/)
 * [Python 2.x](https://www.python.org/downloads/) insalled with Python directory added to your %PATH% environment variable
 * Either gcc 7, or Microsoft Visual C++ 2017
 * An internet connection (for automatic downloading of dependencies)

#### Building
 * Clone the repository to a directory of your choice, SRC.
 * Create a directory for build files, BUILD
 ```
    cd BUILD
    cmake SRC
    cmake --build .
 ```
 * During the first build:
   * If an installation of LLVM is not found it will be downloaded and built automatically.
   * If an installation of yaml-cpp is not found it will downloaded and built automatically.
   * Google test will be downloaded and built.
 * In-source builds seem to work on linux, but building in source with VC++ has some issues.
 * Run either clean.sh or clean.bat to delete in-source build artifacts
 
 #### Visual Studio .sln files
 * On Windows, building will generate `BUILD/project.sln`, and `BUILD/prefix/src/plange-build/plange.sln`. They may be opened in Visual Studio 2017 or later. These solutions correspond to the super build, which need be built only once. Afterwords, the Plange solution can be used for working with the source code.

#### Notes
 * The top level CMakeLists.txt is a super build for preparing dependencies.
   * Plange source code resides in `SRC/source` directory as a separate CMake project.
   * Plange build files reside in `BUILD/prefix/src/plange-build` and may be built directly once the super build completes
 * Downloaded dependencies will be stored in `BUILD/Downloads` and may be deleted once building completes
 * Python is only required if LLVM must be built, or to use miscellaneous python programs within the repository
 * The Ubuntu 16 LTS package `libyaml-cpp-dev` has an undeclared dependency on `libboost-all-dev` and may cause build to fail with fatal `error: boost/shared_ptr.hpp: No such file or directory`. You may:
   * Install boost `sudo apt install libboost-all-dev`, or
   * Uninstall the faulty yaml-cpp package `sudo apt remove libyaml-cpp-dev`, or
   * Modify the CMakeLists.txt files to force an external project in the super build
     * ./CMakeLists.txt
     * ./source/grammar_gen/CMakeLists.txt
 * The Ubuntu 16 LTS package `llvm-3.9-dev` has an undeclared dependency on `zlib1g-dev` and may cause build to fail with `cannot find -lz`. You may:
   * Install zlib `sudo apt install zlib1g-dev`, or
   * Uninstall the faulty LLVM package `sudo apt remove llvm-3.9-dev`, or
   * Modify the CMakeLists.txt files to force an external project in the super build
     * ./CMakeLists.txt
     * ./source/plc/CMakeLists.txt
 
