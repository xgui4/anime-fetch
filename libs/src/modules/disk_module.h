#pragma once

#include "../models/disk_info.hpp" 
#include "module.hpp"
#include <string>
#include <vector>

class DiskModule : public Module {
public:
    DiskModule();
    ~DiskModule();
    std::string display() const override; 
    std::string displayWithArgs(std::vector<std::any>) const override; 
    std::string displayMinimal() const override; 
    std::string displayFeatures() const override; 
private:
    std::vector<DiskInfo> _disks; 

    std::vector<DiskInfo> getDiskInfo(); 
}; 