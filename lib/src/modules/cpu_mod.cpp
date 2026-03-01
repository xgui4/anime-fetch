#include "cpu_mod.h"
#ifdef __linux
#include <hwinfo/cpu.h>
#endif
#include <iostream>
#include <stdexcept>
#include "../utils/cmdline_utils.h"

CPUMod::CPUMod() {
	this->cpus = getCPUInfo(); 
}

CPUMod::~CPUMod() {

}

std::string CPUMod::display() const {
	std::string cpu_info_string = "";
	for (CPUInfo cpu : this->cpus) {
		cpu_info_string += cpu.display() + "\n";
	}
	return cpu_info_string;
}

std::string CPUMod::displayMinimal() const {
	std::string cpu_info_string = ""; 
	for (CPUInfo cpu : this->cpus) {
		cpu_info_string += cpu.displayMinimal() + "\n"; 
	}
	return cpu_info_string; 
}

std::string CPUMod::displayFeatures() const {
	// throw std::runtime_error("Not Implemented Yet!");
	return "NOT IMPLEMENTED YET"; 
}

// private
std::vector<CPUInfo> CPUMod::getCPUInfo()
{
#ifdef __linux__
	try {
		const auto cpus = hwinfo::getAllCPUs();
		auto cpus_info = std::vector<CPUInfo>();

		for (int i = 0; i > cpus.size() - 1; i++) {
			if (cpus.at(i).modelName() != cpus.at(i + 1).modelName()) {
				const CPUInfo cpu = {
					.vendorName = cpus.at(i).vendor(),
					.modelName = cpus.at(i).modelName(),
					.logicalsCores = cpus.at(i).numLogicalCores()
				};
				cpus_info.push_back(cpu);
			};
		}
		return cpus_info;
	}
	catch (std::runtime_error error) {
		std::cout << create_error_str_from_runtime_error(error) << std::endl;
	}
	/*
  #elif _WIN32
	try {
		const auto cpus = hwinfo::getAllCPUs();
		auto cpus_info = std::vector<CPUInfo>();

		for (int i = 0; i > cpus.size() - 1; i++) {
			if (cpus.at(i).modelName() != cpus.at(i + 1).modelName()) {
				const CPUInfo cpu = {
					.vendorName = cpus.at(i).vendor(),
					.modelName = cpus.at(i).modelName(),
					.logicalsCores = cpus.at(i).numLogicalCores()
				};
				cpus_info.push_back(cpu);
			};
		}
		return cpus_info;
	}
	catch (std::runtime_error error) {
		std::cout << create_error_str_from_runtime_error(error) << std::endl;
	}
	*/
#endif
#ifdef __FreeBSD__
	std::vector<CPU_INFO> cpu{
		CPU_INFO{
			"",
			exec("sysctl -n hw.model"),
			std::stoi(exec("sysctl -n hw.ncpu")) }
	};
	return cpu;
#endif
	return std::vector<CPUInfo>{ CPUInfo{ "Error", "Error", 1, 1 } };
}
