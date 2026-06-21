#!/usr/bin/env sh 

set -e

install_vcpkg() {
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    chmod +x "bootstrap-vcpkg.sh"
    ./bootstrap-vcpkg.sh --disable-metrics
    cd ..
}

install_hwinfo_lib() {
    git clone https://github.com/lfreist/hwinfo lib/hwinfo && cd lib/hwinfo
    mkdir build
    cmake -B build && cmake --build build
    cmake --install build
}

if [ "$("whoami")" = "root" ]; then
    install_vcpkg
    install_hwinfo_lib
else
    echo "The prepare script must be running as root"
fi