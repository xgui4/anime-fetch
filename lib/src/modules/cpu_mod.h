#pragma once

#include "../models/cpu_info.hpp" 
#include <string>

class CPUMod {
    public:

    CPUMod();
    ~CPUMod(); 

    std::string display() const; 
    std::string display_features() const; 

    private:
    CPUInfo cpu; 
};