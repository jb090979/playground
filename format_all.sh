#!/bin/bash
SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
echo $SCRIPTPATH

find $SCRIPTPATH -iname *.[hc]pp | xargs clang-format -i --style=file

