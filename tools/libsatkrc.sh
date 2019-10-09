#!/bin/bash

# env variables
export PROOT="/home/anderson/devel/libsatk"
export PNAME="libsatk"
export PBUILD_DIR="$PROOT/build"
export PBUILD_MODE="Debug" # must be either "Debug" or "Release"

# useful shortcuts
alias root='cd $PROOT'
alias build='cd $PBUILD_DIR/$PBUILD_MODE && cmake -DCMAKE_BUILD_TYPE=$PBUILD_MODE "$PROOT" && make'
alias cdbuild='cd $PBUILD_DIR/$PBUILD_MODE'
alias debug='export PBUILD_MODE="Debug" && build'
alias release='export PBUILD_MODE="Release" && build'
alias tools='cd $PROOT/tools'

# reporting
echo
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo "* Project:    $PNAME"
echo "* Directory:  $PROOT"
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo
