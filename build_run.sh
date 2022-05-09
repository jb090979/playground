#!/bin/bash
SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
echo $SCRIPTPATH

pushd $SCRIPTPATH/build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
make all

popd

