#pragma once 

#include <string>

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
    string app_name, 
    string options_desc[] = {},
    string args_list[] = {}
); 
