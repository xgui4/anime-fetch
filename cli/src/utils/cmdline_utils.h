#pragma once

#include <string>
#include "../colors.hpp"

std::string create_hyperlink(std::string title, std::string link); 

std::string generate_colored_string(Color color, std::string input); 

std::string generate_command_block_help_str(
    Color arg1_color,
    string arg1_str, 
    string help_msg,
    Color arg2_color = Color::Default, 
    string arg2_str = "",
    string arg2Alt_str = ""
); 