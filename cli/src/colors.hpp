#pragma once

#include <string>

using std::string; 

// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

enum class Color {
    ForegroundBlack,
    ForegroundRed,
    ForegroundGreen,
    ForegroundYellow,
    ForegroundBlue,
    ForegroundMagenta,
    ForegroundCyan,
    ForegroundWhite,
    BackgroundBlack,
    BackgroundRed,
    BackgroundGreen,
    BackgroundYellow,
    BackgroundBlue,
    BackgroundMagenta,
    BackgroundCyan,
    BackgroundWhite,
    Reset,
    Default
};

inline std::string escapeCode(Color color) {
    switch(color) {
        case Color::ForegroundBlack: 
            return "\033[30m"; 
        case Color::ForegroundRed: 
            return "\033[31m"; 
        case Color::ForegroundGreen:
            return "\033[32m"; 
        case Color::ForegroundYellow:
            return "\033[33m"; 
        case Color::ForegroundBlue: 
            return "\033[34m"; 
        case Color::ForegroundMagenta:
            return "\033[35m";
        case Color::ForegroundCyan: 
            return "\033[36m";
        case Color::ForegroundWhite:
            return "\033[37m"; 
        case Color::BackgroundBlack:
            return "\033[40m"; 
        case Color::BackgroundRed:
            return "\033[41m"; 
        case Color::BackgroundGreen:
            return "\033[42m"; 
        case Color::BackgroundYellow:
            return "\033[43m"; 
        case Color::BackgroundBlue:
            return "\033[44m"; 
        case Color::BackgroundMagenta:
            return "\033[45m"; 
        case Color::BackgroundCyan:
            return "\033[46m"; 
        case Color::BackgroundWhite:
            return "\033[47m"; 
        case Color::Reset:
            return "\033[0m"; 
        case Color::Default:
            return ""; 
        }
}