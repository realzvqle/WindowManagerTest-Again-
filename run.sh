#!/bin/bash

xmake

cp raylib.dll build/linux/x86_64/release/

if [ -d "build/linux/x86_64/release/resources" ]; then
    rm -rf build/linux/x86_64/release/resources
fi

mkdir -p build/linux/x86_64/release/resources

rsync -av --ignore-existing resources/ build/linux/x86_64/release/resources/

xmake run
