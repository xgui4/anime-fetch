#pragma once

#include <string>
#include "../os_type.hpp"

class SystemInfoService {

public: 
    SystemInfoService();
    ~SystemInfoService(); 

    std::string getSystemInfo() const; 
    std::string getOperatingSystemInfo() const; 
    std::string getKernelName() const; 
    std::string getCpuInfo() const; 
    std::string getGpuInfo() const; 
    std::string getMemoryInfo() const; 
    std::string getSwapMemoryInfo() const; 
    std::string getStorageInfo() const; 
    std::string getPackagesInfo() const; 
    std::string getBatteryInfo() const; 
    std::string getThemes() const;
    std::string getWindowManager() const;
    std::string getDesktopEnvironnement() const; 
    std::string getInitSystem() const; 
    std::string getProcessesCountRunning() const; 
private :
    OS_TYPE os_type; 
    
    OS_TYPE getOsType() const;  
}; 
