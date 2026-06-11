#include "system_info_service.h"
#include "../utils/cmdline_utils.h"
#include "../utils/utils.hpp"
#include <iostream>
#include <ostream>

#ifdef __FreeBSD__
  #include <sys/sysctl.h>
#endif

#ifdef __linux__
 #include <hwinfo/cpu.h>
 #include <hwinfo/os.h>
 #include <hwinfo/ram.h>
 #include <hwinfo/hwinfo.h>
#elif _WIN32
 #include <hwinfo/cpu.h>
 #include <hwinfo/os.h>
 #include <hwinfo/ram.h>
 #include <hwinfo/hwinfo.h>
#endif

#include <stdexcept>
#include <modules/cpu_module.h>
#include <modules/gpu_module.h>

SystemInfoService::SystemInfoService() {
      #ifdef _WIN32
      _os_type = OS_TYPE::Windows; 
    #elif __linux__
      _os_type = OS_TYPE::Linux;
    #elif __FreeBSD__
      _os_type = OS_TYPE::BSD; 
    #elif __NetBSD__ 
      _os_type = OS_TYPE::BSD; 
    #elif __OpenBSD__ 
      _os_type = OS_TYPE::BSD; 
    #elif __DragonflyBSD__ 
      _os_type =  OS_TYPE::BSD; 
    #elif __APPLE__
      _os_type =  OS_TYPE::MacOS; 
    #elif __unix__
      _os_type =  OS_TYPE::Unix; 
    #else
      _os_type =  OS_TYPE::Other; 
    #endif
}

SystemInfoService::~SystemInfoService() {

}

std::string SystemInfoService::getOSTan() const {
	std::string os_tan_img_path = ""; 
	if (this->getOsType() == OS_TYPE::Windows) {
      // FIXME : readd the others Windows Version Back! 
			os_tan_img_path = ".anime-fetch\\images\\os-tan\\windows\\windows11-tan.png";
	}
	else if (this->getOsType() == OS_TYPE::MacOS) {
		os_tan_img_path = ".anime-fetch/images/os-tan/mac/system-tan.png";
	}
	else if (this->getOsType() == OS_TYPE::Linux) {
		os_tan_img_path = ".anime-fetch/images/os-tan/linux/arch-1-tan.png";
	}
	else if (this->getOsType() == OS_TYPE::BSD) {
		os_tan_img_path = ".anime-fetch/images/os-tan/bsd/free-bsd-tan.png";
	}
	else if (this->getOsType() == OS_TYPE::Unix) {
		os_tan_img_path = ".anime-fetch/images/os-tan/others/solaris-tan.png";
	}
	else {
		os_tan_img_path = ".anime-fetch/images/os-tan/windows/windows7-tan.png";
	}
	return ""; 
}

std::string SystemInfoService::getSystemInfo() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getOperatingSystemInfo() const {
  #ifdef __linux__
    try {
      return "OS : " +  hwinfo::OS().name(); 
    }
    catch (std::runtime_error error) {
      std::cout << create_error_str_from_runtime_error(error)<< std::endl;; 
      return "OS : Unknow"; 
    }
#elif _WIN32
    try {
        return "OS : " + hwinfo::OS().name();
    }
    catch (std::runtime_error error) {
        std::cout << create_error_str_from_runtime_error(error) << std::endl;
        return "OS : Unknow";
    }
  #endif
  #ifdef __unix
    return  "OS : " + exec("uname -ns"); 
  #endif
  return "OS : Unknown";
}

std::string SystemInfoService::getKernelName() const {
  #ifdef __linux__
      try {
        return "Kernel : " +  hwinfo::OS().kernel(); 
      }
      catch (std::runtime_error error) {
        std::cout << create_error_str_from_runtime_error(error) << std::endl;; 
        return "Kernel : Unknow"; 
      }
  #elif _WIN32
    try {
        return "Kernel : " + hwinfo::OS().kernel();
    }
    catch (std::runtime_error error) {
        std::cout << create_error_str_from_runtime_error(error) << std::endl;
        ;
        return "Kernel : Unknow";
    }
  #elif __unix
    return  "Kernel : " + exec("uname -Kpr"); 
  #endif
  return "Kernel : Unknown";
}

std::string SystemInfoService::getCpuInfo() const {
	try {
		CPUModule cpuModule = CPUModule();
		cpuModule.displayMinimal(); 
	}
	catch (std::runtime_error err){
		std::cout << err.what() << std::endl; 
		return ""; 
	}; 
	return "";
}

std::string SystemInfoService::getGpuInfo() const {
	try {
		GPUModule gpuModule = GPUModule();
		gpuModule.displayMinimal();
	}
	catch (std::runtime_error err) {
		std::cout << err.what() << std::endl;
		return "";
	};
	return "";
}

std::string SystemInfoService::getMemoryInfo() const {
  #ifdef __linux__
    try {
      long bytes = hwinfo::Memory().total_Bytes(); 
      return "Memory : " + bytes_to_gigabytes(bytes) + "GB"; 
    }
    catch (std::runtime_error error) {
      std::cout << create_error_str_from_runtime_error(error)<< std::endl;; 
      return "Kernel : Unknow"; 
    }
  #elif _WIN32
    try {
        long bytes = hwinfo::Memory().total_Bytes();
        return "Memory : " + bytes_to_gigabytes(bytes)  + "GB";
    }
    catch (std::runtime_error error) {
        std::cout << create_error_str_from_runtime_error(error) << std::endl;
        ;
        return "Kernel : Unknow";
    }
  #endif
  #ifdef __FreeBSD__
    return  "Memory : " + exec("sysctl -n hw.realmem"); 
  #endif
   return "TBD";     
 }

std::string SystemInfoService::getSwapMemoryInfo() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getStorageInfo() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getPackagesInfo() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getBatteryInfo() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getThemes() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getWindowManager() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getDesktopEnvironnement() const {
  #ifdef __unix__
    return exec("echo $XDG_CURRENT_DESKTOP"); 
  #endif
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getInitSystem() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getProcessesCountRunning() const {
  throw std::runtime_error("Not Implemented Yet");
}

OS_TYPE SystemInfoService::getOsType() const {
  return _os_type; 
}