#pragma once

#include "lib_config.h"
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

/// DEPRECIATED
string get_about_app_str(string app_title, LibConfig &app_config,  string about_info = "");

string get_about_app_str(string app_title, string about_info, string repo_link, string repo_link_label);

string get_license_info_str(string app_name, string license_info);

int open_gui(string path, const char *args[] = nullptr);

string get_help_info_str(string command_name, string app_name, LibConfig& app_config);