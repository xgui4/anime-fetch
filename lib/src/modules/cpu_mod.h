#pragma once

#include "../models/cpu_info.hpp" 
#include <string>

class CPUMod {
    public:

    CPUMod();
    ~CPUMod(); 

    std::string display() const; 
    std::string displayMinimal() const; 
    std::string displayFeatures() const; 

    private:
	std::vector<CPUInfo> cpus; 

    std::vector<CPUInfo> getCPUInfo(); 
};