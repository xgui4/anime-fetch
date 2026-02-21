#pragma once 

#include <string>
#include "array"

using std::string; 

void display_app_version(
    string app_title, 
    string version
); 

void display_about_app(
    string app_title, 
    string about_info, 
    string repo_link_label, string repo_link
); 

void display_license_info(
    string app_name, 
    string license_info
); 

int open_gui(
    string path, 
    const char* args[] = nullptr
); 

void display_help_info(
    string app_name
); 

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

const std::array<const char*, 10> ARGS_LISTS = std::array<const char*, 10>{
    "--version",
    "-v",
    "--about",
    "-a",
    "--license",
    "-L",
    "--help",
    "-h",
    "--gui",
    "-g"
}; 