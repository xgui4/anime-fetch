#pragma once

#include "../models/battery_info.hpp"
#include "module.hpp"

class BatteryModule : public Module {
public:
	BatteryModule();
	~BatteryModule();

	std::string display() const override;
	std::string displayWithArgs(std::vector<std::any>) const override;
	std::string displayMinimal() const override;
	std::string displayFeatures() const override;

private:
	std::vector<BatteryInfo> batterties;

	std::vector<BatteryInfo> getBatteryInfo();
};