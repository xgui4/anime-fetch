#!/usr/bin/env sh 

set -e

mkdir -p lib

if [ "$("whoami")" = "root" ]; then
    git clone https://github.com/lfreist/hwinfo lib/hwinfo && cd lib/hwinfo
    mkdir build
    cmake -B build && cmake --build build
    cmake --install build
else
    echo "The libray install must be running as root"
fi

# Install configuration: ""
#-- Installing: /usr/local/lib/libhwinfo_battery.so
#-- Installing: /usr/local/include/hwinfo/battery.h
#-- Installing: /usr/local/lib/libhwinfo_cpu.so
#-- Installing: /usr/local/include/hwinfo/cpu.h
#-- Installing: /usr/local/lib/libhwinfo_disk.so
#-- Installing: /usr/local/include/hwinfo/disk.h
#-- Installing: /usr/local/lib/libhwinfo_gpu.so
#-- Installing: /usr/local/include/hwinfo/gpu.h
#-- Installing: /usr/local/lib/libhwinfo_mainboard.so
#-- Installing: /usr/local/include/hwinfo/mainboard.h
#-- Installing: /usr/local/lib/libhwinfo_os.so
#-- Installing: /usr/local/include/hwinfo/os.h
#-- Installing: /usr/local/lib/libhwinfo_ram.so
#-- Installing: /usr/local/include/hwinfo/ram.h
#-- Installing: /usr/local/lib/libhwinfo_network.so
#-- Installing: /usr/local/include/hwinfo/network.h
#-- Installing: /usr/local/include/hwinfo/platform.h
#-- Installing: /usr/local/include/hwinfo/hwinfo.h
#-- Installing: /usr/local/include/hwinfo/utils
#-- Installing: /usr/local/include/hwinfo/utils/PCIMapper.h
#-- Installing: /usr/local/include/hwinfo/utils/filesystem.h
#-- Installing: /usr/local/include/hwinfo/utils/pci.ids.h
#-- Installing: /usr/local/include/hwinfo/utils/stringutils.h
#-- Installing: /usr/local/include/hwinfo/utils/sysctl.h
#-- Installing: /usr/local/include/hwinfo/utils/unit.h
#-- Installing: /usr/local/include/hwinfo/utils/utils.h
#-- Installing: /usr/local/include/hwinfo/utils/wmi_wrapper.h
#-- Installing: /usr/local/lib/cmake/hwinfo/lfreist-hwinfoConfig.cmake
#-- Installing: /usr/local/lib/cmake/hwinfo/lfreist-hwinfoConfigVersion.cmake
#-- Installing: /usr/local/lib/cmake/hwinfo/lfreist-hwinfoTargets.cmake
#-- Installing: /usr/local/lib/cmake/hwinfo/lfreist-hwinfoTargets-noconfig.cmake
#-- Installing: /usr/local/bin/system_info
#-- Set non-toolchain portion of runtime path of "/usr/local/bin/system_info" to "