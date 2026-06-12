#pragma once
#include <string>
#include <vector>
#include <any>

class Module {
public:
	virtual ~Module() = default;

	virtual std::string display() const = 0;
	virtual std::string displayWithArgs(std::vector<std::any>) const = 0; // type to be specified later
	virtual std::string displayMinimal() const = 0;
	virtual std::string displayFeatures() const = 0;
protected:
	Module() = default;
};