# Anime-Fetch

<img src="assets/icons/appicon.png" alt="Anime-Fetch Logo" width="75" height="75">

A noefetch-inspired utility that fetch you system info with a [OS-Tan](https://en.wikipedia.org/wiki/OS-tan)

This is a work in progress experimental cross-platfrom version of [xgui4/wpfetch](https://github.com/xgui4/wpfetch)

## Dependancy/Library needed

- GUI
    - QT 6
- CLI
    - [lfreist/hwinfo](https://github.com/lfreist/hwinfo)
    - Curses
- Global
    - Bash/Shell Script for UNIX and bat file for Windows

## C++ Toolchains

- Clang (C++ 17)

- CMake 3.16 

- QT Widget 6 (for the GUI)

## How to Build and run 

```shell
# 1.
cmake --preset publish 

# 2.
cmake --build --preset publish

# 3.
./build/publish/cli/Anime-Fetch

```

## Helper Scripts 

> [!Note] right now they only support UNIX, coming later for Windows, macOS is not officialy supported since i do not own a Mac

- `install_app.sh` : install the assets ans app in portable modes (need superuser for certain task)
- `install_library.sh`: install the lfreist/hwinfo library (need superuser priviliged)

## License 

[GPLv3](LICENSE.md)

## Code Of Conduct

[Code of Respect](code-of-conduct.md)

## Credits 

[Images Credits](credits.md)
