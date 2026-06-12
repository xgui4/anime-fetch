# Anime-Fetch

![New Anime-Fetch Logo](assets/icons/new-appicon.png)

A neofetch-inspired utility that fetch you system info with a [OS-Tan](https://en.wikipedia.org/wiki/OS-tan)

This is a work in progress experimental cross-platfrom version of [xgui4/wpfetch](https://github.com/xgui4/wpfetch)

## Dependancy/Library needed

- GUI (Unix Like system only for now)
  - QT 6
- CLI
  - [lfreist/hwinfo](https://github.com/lfreist/hwinfo)
    - License : [MIT](LICENSE.lib.txt)
  - Curses

## Recommended System Requirement

> [!TIP]
> There no hard requirement to use any compiler or ide, but here is official supported
> system requirement

### For Compiling

- Unix Like System
  - Clang++ (C++ 17)
  - CMake 3.16+ (CMake 3.19+ recommended for preset)
  - HWinfo Library (installer helper available , only work on Linux thought for now)
  - QT Widget 6 (for the GUI)
- Windows System requirement
  - Visual Studio 2022 or 2026 (Community Edition)
  - CMake 3.16+ (CMake 3.19+ recommended for preset)
  - QT Widget 6 (for the GUI)

### For running the software

- CLI
  - Terminal that support Sixel or Kitty protocol and Color Escape Code (support for legacy terminal coming later)
  - Kitty (for Unix like system only, won't be a hardcoded dependancy for too long)
  - Chafa (for sixel support, won't be a hardcoded dependancy for too long)
- QT GUI
  - QT 6+ (if dynamically linked)
  - A Working Display server like an X Server or Wayland (for system like GNU/Linux, not needed on MacOS or Windows)
- General
  - hwinfo lib (if dynamically linked)

## How to Run or Install

[Compiling Guide](assets/docs/compiling.md)

## License

[GPLv3](LICENSE.md)

## Code Of Conduct

[Code of Respect](code-of-conduct.md)

## Credits

[Images Credits](assets/docs/credits.md)
