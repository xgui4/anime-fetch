#pragma once

#include "configs/lib_config.h"

class AppConfig {
private: 
	LibConfig lib_config; 
public:
	const std::string APP_NAME = "Anime Fetch GUI";

	const std::string EXECUTABLE_NAME = "Anime-Fetch GUI";

	const std::string APP_VERSION = "0.0.0.0";
};