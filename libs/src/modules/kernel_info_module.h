#pragma once

#include "../models/kernel_info.hpp"
#include "module.hpp"

class KernelInfoModule : public Module {
public:
	KernelInfoModule();
	~KernelInfoModule();

	std::string display() const override;
	std::string displayWithArgs(std::vector<std::any>) const override;
	std::string displayMinimal() const override;
	std::string displayFeatures() const override;

private:
	KernelInfo kernelInfo;

	std::string getKernelInfo();
}; 


/*

#pragma once

#include "../models/kernel_info.hpp"
#include "module.hpp"

class BatteryModule : public Module {
public:
	KernelModule();
	~KernelInfoModule();

	std::string display() const override;
	std::string displayWithArgs(std::vector<std::any>) const override;
	std::string displayMinimal() const override;
	std::string displayFeatures() const override;

private:
	std::string kernelInfo;

	std::string getKernelInfo();
};


*/