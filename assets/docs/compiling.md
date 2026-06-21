# Compiling Guide

## How to Run or Install

### Unix Like System

> [!WARNING]
> The preparation script is a work in progress and may not work as intended.

```bash
# 1. If the library not installed yet
sudo ./prepare.sh

# 2. Build the Min Size Release with CMake (CMake Required)
cmake --build --preset MinSizeRel

# 3.
./build/publish/cli/anime-fetch
```

### Windows (Visual Studio with QT-tools addon)

> [!NOTE]
> Due to the complexity of the Windows Dev ecosytem, I will only show the easy way with Visual Studio and MSVC.
> But the App should not require any binary blob to work outside of msvrt (Visual C++,  if Visual Studio is used).

1. Install Visual Studio Community (<https://visualstudio.microsoft.com/>)
2. Install the QT Visual Studio Tools Addon via the Extension Store or via this link (<https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2022>)
3. Install QT 6 for Windows and add it your path (there is multiple way but make sure to install the "open soure" one)
4. Set the QT Path with The QT Path
5. Run or Debug the software via Visual Studio by the selecting either the `anime-fetch.exe` (CLI) or [need QT-Debug or QT-Release] `anime-fetch-gui` (QT GUI)

### Windows Wizard Creation

```bash

# GUIDE COMING SOON !

```

### Linux and *BSD Packaging

```bash

# GUIDE Coming Soon !

```
