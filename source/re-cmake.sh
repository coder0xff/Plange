#!/bin/bash

set -ex

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
mkdir -p ~/Desktop/plange
pushd ~/Desktop/plange
rm -rf *
cmake $DIR
make -j 4
popd
