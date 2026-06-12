#pragma once

#include "../models/cpu_info.hpp" 
#include "module.hpp"
#include <string>
#include <vector>

class CPUModule : public Module {
public:
  CPUModule();
  ~CPUModule(); 

  std::string display() const override; 
  std::string displayWithArgs(std::vector<std::any>) const override; 
  std::string displayMinimal() const override; 
  std::string displayFeatures() const override; 

private:
  std::vector<CPUInfo> _cpus; 

  std::vector<CPUInfo> getCPUInfo(); 
};