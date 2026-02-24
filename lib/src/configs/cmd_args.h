#pragma once

#include "app_config.h"
#include <string>
#include <array>

using std::string;

enum class CmdLineArgs {
  CmdVersion,
  CmdVersionShort,
  CmdAbout,
  CmdAboutShort,
  CmdLicense,
  CmdLicenseShort,
  CmdHelp,
  CmdHelpShort,
  CmdGui,
  CmdGuiShort
};

const std::array<const char *, 10> ARGS_LISTS = std::array<const char *, 10>{
    "--version", "-v",     "--about", "-a",    "--license",
    "-L",        "--help", "-h",      "--gui", "-g"};

string get_app_version_str(string app_title, string version);

string get_about_app_str(string app_title, AppConfig &app_config,  string about_info = "");

string get_license_info_str(string app_name, string license_info);

int open_gui(string path, const char *args[] = nullptr);

string get_help_info_str(string app_name, AppConfig& app_config);