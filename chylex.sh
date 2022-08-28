#!/bin/sh
set -e

./mach clobber
./mach build
./mach package
./mach build installers-cs

echo "Built installers are in: ./obj-x86_64-pc-mingw32\dist\install\sea"
