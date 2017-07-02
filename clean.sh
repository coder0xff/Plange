#!/bin/bash

pushd `dirname $0`
rm -rf CMakeFiles
rm -rf Debug
rm -rf Dependencies
rm -rf Downloads
rm -rf prefix
rm -rf Release
rm -rf Win32
rm -f *.vcxproj*
rm -f CMakeCache.txt
rm -f cmake_install.cmake
rm -f Project.sln
popd

