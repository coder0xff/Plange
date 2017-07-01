# Plange
A project to create a revolutionary development environment

For documentation, see the [plange.tech](http://plange.tech) website.

The instructions below use `./` to donate the location in which the plange source code has been downloaded/cloned to.

## Building
CMake is used to build Plange. Build has been tested on Visual Studio 2017, and gcc 7.

#### Prerequisites
 * [CMake](https://cmake.org/download/)
 * [Python](https://www.python.org/downloads/) 2.x (with install directory added to your %PATH% environment variable)
 * Either gcc 7, or Microsoft Visual C++ 2017
 * An internet connection (for automatic downloading of dependencies)

#### Building
 * Clone the repository to a directory of your choice.
 * Create a location for the build files in a directory of your choice.
 * Run cmake in the build directory, specifying the source directory
 * Build
   * On Linux, run `make` in the build directory
   * On Windows, open the newly created "project.sln" in Visual Studio, and build/run as usual
 * During the first build:
   * If an installation of LLVM is not found it will be downloaded and built automatically.
   * If an installation of yaml-cpp is not found it will downloaded and built automatically.
   * Google test will be downloaded and built.

#### Notes
 * The top level CMakeLists.txt is a super build for preparing dependencies.
   * Plange source code resides in `./source` directory as a separate CMake project.
   * Plange build files reside in `build/prefix/src/plange-build` and may be built directly once the super build completes
 * Downloaded dependencies will be stored in `(BUILD_DIRECTORY)/Downloads` and may be deleted once built
 * The Python prerequisite is only required if LLVM is not installed, because building LLVM requires Python.
 * The Ubuntu 16 LTS package `libyaml-cpp-dev` has an undeclared dependency on `libboost-all-dev` and may cause build to fail with fatal `error: boost/shared_ptr.hpp: No such file or directory`. You may:
   * Install boost `sudo apt install libboost-all-dev`, or
   * Uninstall the faulty yaml-cpp package (so the super build will acquire it automatically) `sudo apt remove libyaml-cpp-dev`, or
   * Modify the CMakeLists.txt files to force super build acquisition
     * ./CMakeLists.txt
     * ./source/grammar_gen/CMakeLists.txt
 * The Ubuntu 16 LTS package `llvm-3.9-dev` has an undeclared dependency on `zlib1g-dev` and may cause build to fail with `cannot find -lz`. You may:
   * Install zlib `sudo apt install zlib1g-dev`, or
   * Uninstall the faulty llvm package (so the super build will acquire it automatically) `sudo apt remove llvm-3.9-dev`, or
   * Modify the CMakeLists.txt files to force super build acquisition
     * ./CMakeLists.txt
     * ./source/plc/CMakeLists.txt
 
