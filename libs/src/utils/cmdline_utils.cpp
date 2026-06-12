#include "cmdline_utils.h"

const std::string OSC = "\e]";
const std::string OSC_8 = ";;8";
const std::string ST = "\e\\";

// https://askubuntu.com/questions/1391071/creating-a-hyperlink-from-command-line-output-on-a-terminal

std::string create_link(std::string title, std::string link) {

  std::string hyperlink_code =
      OSC + OSC_8 + link + ST + title + OSC + OSC_8 + ST;

  return hyperlink_code;
}

std::string create_colored_str(Color color, std::string input) {
  return escapeCode(color) + input + escapeCode(Color::Reset);
}

std::string gen_cmd_block_help_str(Color arg1_color, string arg1_str,
                                            string help_msg, Color arg2_color,
                                            string arg2_str,
                                            string arg2Alt_str) {
  string argument1 = create_colored_str(arg1_color, arg1_str);

  string argument2 = create_colored_str(arg2_color, arg2_str);
  string argument2Alt = create_colored_str(arg2_color, arg2Alt_str);

  if (!empty(arg2Alt_str)) {
    return argument1 + " " + argument2 + " [or] " + argument2Alt + " | " +
           help_msg;
  }

  return argument1 + " | " + help_msg;
}

std::string create_error_str_from_runtime_error(std::runtime_error error) {
  return create_colored_str(Color::ForegroundRed, "Error : ") + error.what(); 
}