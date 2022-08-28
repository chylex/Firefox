#!/bin/sh
set -e

./mach build
./mach package
./mach build installers-cs

echo "Built installers are in: ./obj-x86_64-pc-windows-msvc\dist\install\sea"
