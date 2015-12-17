#!/bin/bash

set -e -o pipefail -u
DIR=$(pwd)
cd "$( dirname "${BASH_SOURCE[0]}" )"
#autoreconf
mkdir -p build
cd build
#../configure CFLAGS="-g3 -O0" CXXFLAGS="-g3 -O0" CXX="clang++"
make
cd test
#ddd test
cd "$DIR"