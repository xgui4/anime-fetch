#include "gpu_module.h"
#include <stdexcept>
#include <hwinfo/gpu.h>

GPUModule::GPUModule() {
}

GPUModule::~GPUModule() {
}

std::string GPUModule::display() const {
	return std::string();
}

std::string GPUModule::displayWithArgs(std::vector<std::any>) const {
	return std::string();
}

std::string GPUModule::displayMinimal() const {
	return std::string();
}

std::string GPUModule::displayFeatures() const {
	return std::string();
}

std::vector<GPUInfo> GPUModule::getGPUInfo() {
#ifdef WIN32
	std::vector<hwinfo::GPU> gpus_obj = hwinfo::getAllGPUs();
	auto gpus = std::vector<GPUInfo>();

	if (gpus_obj.empty()) {
		return {};
	}

	for (auto& gpu : gpus_obj) {
		auto new_gpu = GPUInfo {
			gpu.vendor(),
			gpu.name()
		};
		gpus.push_back(new_gpu);
	}
	return gpus;
#elif __linux__
	std::vector<hwinfo::GPU> gpus_obj = hwinfo::getAllGPUs();
	auto gpus = std::vector<GPUInfo>();

	if (gpus_obj.empty()) {
		return {};
	}

	for (auto& gpu : gpus_obj) {
		auto new_gpu = GPUInfo{
			gpu.vendor(),
			gpu.modelName()
		};
		gpus.push_back(new_gpu);
	}
	return gpus;
#endif
	throw std::runtime_error("Platform not supprted yet");
}
