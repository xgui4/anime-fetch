#include "system_info_service.hpp"
#include "../utils/cmdline_utils.h"
#include <iostream>
#include <stdexcept>

    SystemInfoService::SystemInfoService() {
        std::cout << generate_colored_string(Color::ForegroundCyan, "[Info]") <<  "System Info Service Started!" << std::endl; 
        os_type = this->getOsType(); 
    }

    SystemInfoService::~SystemInfoService() {
        std::cout << generate_colored_string(Color::ForegroundCyan, "[Info]") <<  "System Info Service Stopped!" << std::endl; 
    }

    std::string SystemInfoService::getSystemInfo() const{
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getOperatingSystemInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    } 

    std::string SystemInfoService::getKernelName() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    } 

    std::string SystemInfoService::getCpuInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getGpuInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getMemoryInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getSwapMemoryInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getStorageInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getPackagesInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getBatteryInfo() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getThemes() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getWindowManager() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getDesktopEnvironnement() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getInitSystem() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }

    std::string SystemInfoService::getProcessesCountRunning() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }
    
    OS_TYPE SystemInfoService::getOsType() const {
        throw new std::runtime_error("Not Implemented Yet"); 
    }