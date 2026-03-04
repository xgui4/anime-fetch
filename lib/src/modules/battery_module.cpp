#include "battery_module.h"
#include <stdexcept>

#ifdef WIN32
#include <hwinfo/hwinfo.h>
#elif __linux__
#include <hwinfo/hwinfo.h>
#endif

BatteryModule::BatteryModule() : Module() {

}

BatteryModule::~BatteryModule() {
}

std::string BatteryModule::display() const {
	return std::string();
}

std::string BatteryModule::displayWithArgs(std::vector<std::any>) const {
	return std::string();
}

std::string BatteryModule::displayMinimal() const {
	return std::string();
}

std::string BatteryModule::displayFeatures() const {
	return std::string();
}

std::vector<BatteryInfo> BatteryModule::getBatteryInfo() {
#ifdef __linux__
	std::vector<hwinfo::Battery> batteries_obj = hwinfo::getAllBatteries();
	auto batteries = std::vector<BatteryInfo>();

	if (batteries_obj.empty()) {
		return {};
	}

	for (auto& battery : batteries_obj) {
		auto new_bat = BatteryInfo{
			battery.vendor(),
			battery.model(),
			battery.technology(),
			battery.capacity(),
			std::to_string(battery.charging())
		}; 
		batteries.push_back(new_bat); 
	}
	return batteries; 
#endif
	throw std::runtime_error("Platform not supprted yet");
}
