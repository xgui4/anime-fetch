#!/usr/bin/env sh

set -e

git clone https://github.com/microsoft/vcpkg.git

cd vcpkg

bootstrap-vcpkg.sh