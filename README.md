# Plange
A project to create a revolutionary development environment

For documentation, see the [plange.tech](http://plange.tech) website.

The instructions below use `./` to donate the location in which the plange source code has been downloaded/cloned to.

## Cloning
Make sure to clone the `./source/plc/symengine` submodule as well. ([instructions](http://stackoverflow.com/a/4438292/395029)).

## Building
CMake is used to build Plange. 

### Building with Visual C++
Support for building in MSVC++ is very hacky, but worked when last tested with Visual Studio 2015 (2016-08-14)

#### Prerequisites
 * [CMake](https://cmake.org/download/)
 * [Python](https://www.python.org/downloads/) 2.x (with install directory added to your %PATH% environment variable)
 * Microsoft Visual C++ 2010 or newer, or [Visual C++ 2015 Express](https://www.visualstudio.com/products/visual-studio-express-vs)
 * An internet connection (for automatic downloading of [LLVM](http://llvm.org/releases/download.html) and [MPIR](mpir.org) sources)

#### Building
 * Run cmake (or cmake-gui) with the source path set to the `./source` directory.
 * This process downloads and builds third-party sources, which causes the first run to take some time
 * Open the newly created "plange.sln" in Visual Studio, and build/run as usual
 
#### Caveats
 * compiling the MPIR library requires the assembler vsyasm.exe to be installed in your MSVC++ bin directory. `./source/cmake/Modules/vsyasm_install.cmake` will download and install vsyasm if you run CMake with administrative privileges. Otherwise you must [install it yourself](http://yasm.tortall.net/Download.html).
 * There is an assortment of other hacks intended to make this process easier, but which may fail or may not be appropriate for your setup. Check the `./source/cmake/Modules` directory to see what is being attempted.
 * Downloaded files will be stored in `(BUILD_DIRECTORY)/Downloads` and may be deleted once the corresponding binaries have been built.

### Building on Unix like systems

#### Prerequisites
These prerequisites should be available in your *nix distributions package manager

 * CMake
 * Python 2.x
 * gmp ([GNU multi-precision library](https://gmplib.org/))
 * llvm-3.8-dev

#### Caveats
 * There is an issue in Ubuntu 16.04 TLS causing the LLVM dev package to be installed incorrectly. You may need to build and install LLVM yourself, and then set LLVM_DIR (in CMake) to `(LLVM_INSTALL_DIR)/share/llvm/cmake`
