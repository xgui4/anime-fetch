#include "cmdline_utils.h"

const std::string OSC = "\e]"; 
const std::string OSC_8 = ";;8"; 
const std::string ST = "\e\\";

// https://askubuntu.com/questions/1391071/creating-a-hyperlink-from-command-line-output-on-a-terminal

std::string create_hyperlink(std::string title, std::string link) {

    std::string hyperlink_code = 
    OSC + 
    OSC_8 + 
    link + 
    ST + 
    title + 
    OSC + 
    OSC_8 + 
    ST;

    return hyperlink_code; 
}

std::string generate_colored_string(Color color, std::string input) {
    return escapeCode(color) + input + escapeCode(Color::Reset); 
}

std::string generate_command_block_help_str(
    Color arg1_color,
    string arg1_str, 
    string help_msg,
    Color arg2_color,
    string arg2_str,
    string arg2Alt_str
) 
{
    string argument1 = generate_colored_string(arg1_color, arg1_str);

    string argument2 = generate_colored_string(arg2_color, arg2_str);
    string argument2Alt = generate_colored_string(arg2_color, arg2Alt_str);

    if (!empty(arg2Alt_str)) {
        return argument1 + " " + argument2 + " [or] " + argument2Alt + " | " + help_msg; 
    }

    return argument1 +  " | " + help_msg; 
} 