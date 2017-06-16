#!/bin/bash

pushd `pwd`

./fix_graphics.sh

cd ..
rm -rf build
mkdir build
cd build

cmake -G "Unix Makefiles" .. -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Release
make && ctest && make install && cpack -G "TGZ"

popd
