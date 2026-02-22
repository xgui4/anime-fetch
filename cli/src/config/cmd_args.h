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

void display_app_version(string app_title, string version);

void display_about_app(string app_title, AppConfig &app_config,  string about_info = "");

void display_license_info(string app_name, string license_info);

int open_gui(string path, const char *args[] = nullptr);

void display_help_info(string app_name, AppConfig& app_config);