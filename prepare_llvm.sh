#!/bin/bash

set -ex

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
rm -rf $HOME/Desktop/llvm-3.8.1.build
rm -rf $HOME/Desktop/llvm-3.8.1.install
mkdir -p $HOME/Desktop/llvm-3.8.1.build
pushd $HOME/Desktop/llvm-3.8.1.build
cmake -DCMAKE_INSTALL_PREFIX=$HOME/Desktop/llvm-3.8.1.install $DIR/llvm-3.8.1.src
make install
popd
mkdir -p $DIR/llvm-3.8.1
cp -r $HOME/Desktop/llvm-3.8.1.install/lib $DIR/llvm-3.8.1/lib
cp -r $HOME/Desktop/llvm-3.8.1.install/include $DIR/llvm-3.8.1/include
