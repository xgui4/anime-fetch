#pragma once

#include "../colors.hpp"
#include <stdexcept>
#include <string>

std::string create_link(std::string title, std::string link);

std::string create_colored_str(Color color, std::string input);

std::string gen_cmd_block_help_str(Color arg1_color, string arg1_str,
                                            string help_msg,
                                            Color arg2_color = Color::Default,
                                            string arg2_str = "",
                                            string arg2Alt_str = "");

std::string create_error_str_from_runtime_error(std::runtime_error error);