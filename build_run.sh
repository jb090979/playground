#!/bin/bash
SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
echo $SCRIPTPATH

mkdir -p "build_gcc"
pushd $SCRIPTPATH/build_gcc
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
make all
popd


#mkdir -p "build_clang"
#pushd $SCRIPTPATH/build_clang
#export CC=/usr/bin/clang
#export CXX=/usr/bin/clang++
#export LD=/usr/bin/llvm-ld
#cmake .. -D_CMAKE_TOOLCHAIN_PREFIX=llvm- -DCMAKE_LINKER=/usr/bin/llvm-ld  -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
#make all
#popd

