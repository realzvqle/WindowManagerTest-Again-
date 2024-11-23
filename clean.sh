#!/bin/bash

if [ -d "build" ]; then
    rm -rf build
fi

if [ -d ".xmake" ]; then
    rm -rf .xmake
fi