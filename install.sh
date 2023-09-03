#!/bin/bash

if ! command -v which cmake > /dev/null 2>&1 /dev/null
then
    echo "cmake could not be found"
    exit
fi

echo "Cleaning..."
rm -Rdf build/ > /dev/null 2>&1 /dev/null
mkdir build/
CWD=$(pwd)
cp -r src build/

echo "Building..."
cd "${CWD}/build/" && cmake "$CWD"
#cp "${CWD}/Kbuild" "${CWD}/build/Makefile"
cmake --build "${CWD}/build/"
cd "$CWD" || exit | exit

echo "Build complete!"