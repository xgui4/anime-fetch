#include "system_info_service.hpp"
#include "../utils/cmdline_utils.h"
#include "../utils/utils.hpp"
#include <hwinfo/cpu.h>
#include <hwinfo/os.h>
#include <hwinfo/ram.h>
#include <iostream>
#include <stdexcept>
#include <hwinfo/hwinfo.h>
#include <vector>

SystemInfoService::SystemInfoService() {
  std::cout << create_colored_str(Color::ForegroundCyan, "[Info]")
            << "System Info Service Started!" << std::endl;
  os_type = this->getOsType();
}

SystemInfoService::~SystemInfoService() {
  std::cout << create_colored_str(Color::ForegroundCyan, "[Info]")
            << "System Info Service Stopped!" << std::endl;
}

std::string SystemInfoService::getSystemInfo() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getOperatingSystemInfo() const {
  try {
    return "OS : " +  hwinfo::OS().name(); 
  }
  catch (std::runtime_error error) {
    std::cout << create_error_str_from_runtime_error(error)<< std::endl;; 
    return "OS : Unknow"; 
  }
}

std::string SystemInfoService::getKernelName() const {
  try {
    return "Kernel : " +  hwinfo::OS().kernel(); 
  }
  catch (std::runtime_error error) {
    std::cout << create_error_str_from_runtime_error(error)<< std::endl;; 
    return "Kernel : Unknow"; 
  }
}

std::vector<CPU_INFO> SystemInfoService::getCpuInfo() const {
  try {
    const auto cpus = hwinfo::getAllCPUs();
    std::vector<CPU_INFO> cpus_info = std::vector<CPU_INFO>();  

    for (int i = 0; i > cpus.size() - 1; i++) {
      if (cpus.at(i).modelName() != cpus.at(i+1).modelName())  {
          const CPU_INFO cpu = {
              cpus.at(i).vendor(),
              cpus.at(i).modelName(),
              cpus.at(i).numLogicalCores()
          };
          cpus_info.push_back(cpu); 
      }; 
    }
    return cpus_info;  
  }
  catch (std::runtime_error error) {
    std::cout << create_error_str_from_runtime_error(error) << std::endl; 
  }
  return std::vector<CPU_INFO> {CPU_INFO { "Error", "Error", 1}};
}

std::vector<GPU_INFO> SystemInfoService::getGpuInfo() const {
  try {
    const auto gpus = hwinfo::getAllGPUs();
    std::vector<GPU_INFO> gpus_info = std::vector<GPU_INFO>();  

    for (int i = 0; i > gpus.size() - 1; i++) {
      if (gpus.at(i).name() != gpus.at(i+1).name())  {
          const GPU_INFO gpu = {
              gpus.at(i).vendor(),
              gpus.at(i).name(),
              std::to_string(gpus.at(i).memory_Bytes())
          };
          gpus_info.push_back(gpu); 
      }; 
    }
    return gpus_info;  
  }
  catch (std::runtime_error error) {
    std::cout << create_error_str_from_runtime_error(error) << std::endl; 
  }
  return std::vector<GPU_INFO> {GPU_INFO { "Error", "Error", "Error"}};
}

std::string SystemInfoService::getMemoryInfo() const {
  try {
    long bytes = hwinfo::Memory().total_Bytes(); 
    return "Memory : " + bytes_to_gigabytes(bytes); 
  }
  catch (std::runtime_error error) {
    std::cout << create_error_str_from_runtime_error(error)<< std::endl;; 
    return "Kernel : Unknow"; 
  }
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
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getInitSystem() const {
  throw std::runtime_error("Not Implemented Yet");
}

std::string SystemInfoService::getProcessesCountRunning() const {
  throw std::runtime_error("Not Implemented Yet");
}

OS_TYPE SystemInfoService::getOsType() const {
    #ifdef _WIN32
        return OS_TYPE::Windows; 
    #elif __linux__
        return OS_TYPE::Linux;
    #elif __APPLE__
        return OS_TYPE::MacOS; 
    #elif __Unix__
        return OS_TYPE::Unix; 
    #elif __BSD__
        return OS_TYPE::BSD; 
    #else
        return OS_TYPE::Other; 
    #endif
}