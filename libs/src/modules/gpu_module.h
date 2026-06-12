#pragma once

#include "module.hpp"
#include <models/gpu_info.hpp>

class GPUModule : public Module {
public:
	GPUModule();
	~GPUModule();

	std::string display() const override;
	std::string displayWithArgs(std::vector<std::any>) const override;
	std::string displayMinimal() const override;
	std::string displayFeatures() const override;

private:
	std::vector<GPUInfo> _gpus;

	std::vector<GPUInfo> getGPUInfo();
}; 