#include "cpu_module.h"

#ifdef __linux
#include <hwinfo/hwinfo.h>
#include <hwinfo/cpu.h>
#endif
#ifdef WIN32
// #include <hwinfo/hwinfo.h>
// #include <hwinfo/cpu.h>
#endif

#include <iostream>
#include <stdexcept>
#include "../utils/cmdline_utils.h"

CPUModule::CPUModule() : Module() {
	this->_cpus = getCPUInfo(); 
}

CPUModule::~CPUModule() {

}

std::string CPUModule::display() const {
	std::string cpu_info_string = "";
	for (CPUInfo cpu : this->_cpus) {
		cpu_info_string += cpu.display() + "\n";
	}
	return cpu_info_string;
}

std::string CPUModule::displayWithArgs(std::vector<std::any>) const {
	return std::string();
}

std::string CPUModule::displayMinimal() const {
	std::string cpu_info_string = ""; 
	for (CPUInfo cpu : this->_cpus) {
		cpu_info_string += cpu.displayMinimal() + "\n"; 
	}
	return cpu_info_string; 
}

std::string CPUModule::displayFeatures() const {
    throw std::runtime_error("Not Implemented Yet!");
}

// private
std::vector<CPUInfo> CPUModule::getCPUInfo() {
#ifdef WIN32
	throw std::runtime_error("Disabled temporaly due to a linker issue");
#elif __linux__

	std::vector<hwinfo::CPU> cpus_obj = hwinfo::getAllCPUs();
	auto cpus = std::vector<CPUInfo>();

	if (cpus_obj.empty()) {
		return {};
	}

	for (auto& cpu : cpus_obj) {
		auto new_cpu = CPUInfo {
			cpu.vendor(),
			cpu.modelName(),
			-1, 
			-1, 
			cpu.numPhysicalCores(),
			cpu.numLogicalCores(), 
			cpu.L1CacheSize_Bytes(), 
			cpu.L2CacheSize_Bytes(),
			cpu.L3CacheSize_Bytes()
		};
		cpus.push_back(new_cpu);
	}
	return cpus;
#elif __FreeBSD__
	std::vector<CPUInfo> cpu {
		CPUInfo {
			""
			exec("sysctl -n hw.model"),
			-1, 
			std::stoi(exec("sysctl -n hw.ncpu")),
			-1,
			-1,
			-1,
			-1,
			-1
		}
	};
	return cpu;
#endif
	throw std::runtime_error("Platform not supprted yet");
}

