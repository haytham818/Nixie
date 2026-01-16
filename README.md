<div align="center">

# Nixie

**Declarative, Single-File 2D Game Prototyping Engine**

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![Lua](https://img.shields.io/badge/Lua-5.4-blue.svg)](https://www.lua.org/)

[English](README.md) | [简体中文](docs/README.CHS.md)

</div>

---

Inspired by NixOS, Nixie is a **declarative**, **single-file** driven 2D game prototyping engine.

In this engine, there are no complex class hierarchies or scene managements. The entire game state, logic, and asset mapping are defined within a single Lua Table.

## Features

- **Declarative** — Game as Data. Describe what the game state should be, not how to process it.
- **Single File** — All configurations, entity definitions, and update logic exist in **one** file. Easy to share, easy to version control.
- **Thin** — Built on a **C++** and **Raylib** backend, interacting with **Lua via Sol2**.
- **Prototype First** — Designed for **Game Jams** and rapid gameplay verification. Write games like you write configuration files.

## Dependencies

- [Raylib](https://www.raylib.com/) - Simple and easy-to-use graphics library
- [Sol2](https://github.com/ThePhD/sol2) - C++ ↔ Lua binding library
- [Lua 5.4](https://www.lua.org/) - Scripting language

> **Note:** All dependencies are automatically downloaded via CMake FetchContent during build.

## Building

### Prerequisites

- CMake 3.16+
- C++17 compatible compiler (GCC 8+, Clang 7+, MSVC 2019+)
- Ninja (recommended) or Make

**Linux additional packages:**
```bash
# Debian/Ubuntu
sudo apt install build-essential cmake ninja-build libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev

# Fedora
sudo dnf install gcc-c++ cmake ninja-build libX11-devel libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel mesa-libGL-devel

# Arch
sudo pacman -S base-devel cmake ninja libx11 libxrandr libxinerama libxcursor libxi mesa
```

### Build Commands

**Linux:**
```bash
# Configure (Debug)
cmake --preset linux-debug

# Build
cmake --build --preset linux-debug

# Or Release build
cmake --preset linux-release
cmake --build --preset linux-release
```

**Windows (with Ninja):**
```bash
cmake --preset windows-debug
cmake --build --preset windows-debug
```

**Windows (with Visual Studio):**
```bash
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
