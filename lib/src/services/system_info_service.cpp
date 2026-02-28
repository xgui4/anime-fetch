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
#include <vector>

SystemInfoService::SystemInfoService() {
      #ifdef _WIN32
      os_type = OS_TYPE::Windows; 
    #elif __linux__
      os_type = OS_TYPE::Linux;
    #elif __FreeBSD__
      os_type = OS_TYPE::BSD; 
    #elif __NetBSD__ 
      os_type = OS_TYPE::BSD; 
    #elif __OpenBSD__ 
      os_type = OS_TYPE::BSD; 
    #elif __DragonflyBSD__ 
      os_type =  OS_TYPE::BSD; 
    #elif __APPLE__
      os_type =  OS_TYPE::MacOS; 
    #elif __unix__
      os_type =  OS_TYPE::Unix; 
    #else
      os_type =  OS_TYPE::Other; 
    #endif
}

SystemInfoService::~SystemInfoService() {
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
		;
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

std::vector<CPUInfo> SystemInfoService::getCpuInfo() const {
  #ifdef __linux__
    try {
      const auto cpus = hwinfo::getAllCPUs();
      auto cpus_info = std::vector<CPUInfo>();  

      for (int i = 0; i > cpus.size() - 1; i++) {
        if (cpus.at(i).modelName() != cpus.at(i+1).modelName())  {
            const CPUInfo cpu = {
                .vendor_name = cpus.at(i).vendor(),
                .model_name = cpus.at(i).modelName(),
                .logicals_cores = cpus.at(i).numLogicalCores()
            };
            cpus_info.push_back(cpu); 
        }; 
      }
      return cpus_info;  
    }
    catch (std::runtime_error error) {
      std::cout << create_error_str_from_runtime_error(error) << std::endl; 
    }
  #elif _WIN32
    try {
		const auto cpus = hwinfo::getAllCPUs();
		auto cpus_info = std::vector<CPUInfo>();

		for (int i = 0; i > cpus.size() - 1; i++) {
			if (cpus.at(i).modelName() != cpus.at(i + 1).modelName()) {
				const CPUInfo cpu = {
					.vendor_name = cpus.at(i).vendor(),
					.model_name = cpus.at(i).modelName(),
					.logicals_cores = cpus.at(i).numLogicalCores()
				};
				cpus_info.push_back(cpu);
			};
		}
		return cpus_info;
	}
	catch (std::runtime_error error) {
		std::cout << create_error_str_from_runtime_error(error) << std::endl;
	}
  #endif
  #ifdef __FreeBSD__
    std::vector<CPU_INFO> cpu{ 
      CPU_INFO {
        "",
        exec("sysctl -n hw.model"),
        std::stoi (exec("sysctl -n hw.ncpu"))
      }
    };
    return cpu; 
  #endif
  return std::vector<CPUInfo> {CPUInfo { "Error", "Error", 1, 1}};
}

std::vector<GPUInfo> SystemInfoService::getGpuInfo() const {
  #ifdef __linux__
    try {
      const auto gpus = hwinfo::getAllGPUs();
      auto gpus_info = std::vector<GPUInfo>();  

      for (int i = 0; i > gpus.size() - 1; i++) {
        if (gpus.at(i).name() != gpus.at(i+1).name())  {
            const GPUInfo gpu = {
                .vendor_name = gpus.at(i).vendor(),
                .model_name = gpus.at(i).name(),
                .memory = std::to_string(gpus.at(i).memory_Bytes())
            };
            gpus_info.push_back(gpu); 
        }; 
      }
      return gpus_info;  
    }
    catch (std::runtime_error error) {
      std::cout << create_error_str_from_runtime_error(error) << std::endl; 
    }
  #elif _WIN32
	try {
		const auto gpus = hwinfo::getAllGPUs();
		auto gpus_info = std::vector<GPUInfo>();

		for (int i = 0; i > gpus.size() - 1; i++) {
			if (gpus.at(i).name() != gpus.at(i + 1).name()) {
				const GPUInfo gpu = {
					.vendor_name = gpus.at(i).vendor(),
					.model_name = gpus.at(i).name(),
					.memory = std::to_string(gpus.at(i).memory_Bytes())
				};
				gpus_info.push_back(gpu);
			};
		}
		return gpus_info;
	}
	catch (std::runtime_error error) {
		std::cout << create_error_str_from_runtime_error(error) << std::endl;
	}
  #endif
  return std::vector<GPUInfo> {GPUInfo {"Error", "Error", "Error"}};
}

std::string SystemInfoService::getMemoryInfo() const {
  #ifdef __linux__
    try {
      long bytes = hwinfo::Memory().total_Bytes(); 
      return "Memory : " + bytes_to_gigabytes(bytes); 
    }
    catch (std::runtime_error error) {
      std::cout << create_error_str_from_runtime_error(error)<< std::endl;; 
      return "Kernel : Unknow"; 
    }
  #elif _WIN32
	try {
		long bytes = hwinfo::Memory().total_Bytes();
		return "Memory : " + bytes_to_gigabytes(bytes);
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
  return os_type; 
}