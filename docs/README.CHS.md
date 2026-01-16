<div align="center">

# Nixie

**声明式、单文件驱动的 2D 游戏原型引擎**

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](../LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![Lua](https://img.shields.io/badge/Lua-5.4-blue.svg)](https://www.lua.org/)

[English](../README.md) | [简体中文](README.CHS.md)

</div>

---

受到了 NixOS 的启发，Nixie 是一个**声明式**、**单文件驱动**的 2D 游戏原型引擎。

在这个引擎中，你不需要编写复杂的类继承或进行复杂的场景管理，整个游戏的状态、逻辑和资源映射都仅仅是一个 Lua Table。

## Features

- **声明式** — 游戏即数据。通过描述"游戏应该是什么样"，而不是"游戏该怎么运行"。
- **单文件** — 所有的配置、实体定义和更新逻辑都存在于**一个**文件中。易于分享，易于版本控制。
- **轻量级** — 基于 **C++** 和 **Raylib** 后端，通过 **Sol2 与 Lua 交互**。
- **面向原型** — 专为 **Game Jam** 和快速验证玩法设计。像编写配置文件一样编写游戏。

## Dependencies

- [Raylib](https://www.raylib.com/) - 简洁易用的图形库
- [Sol2](https://github.com/ThePhD/sol2) - C++ ↔ Lua 绑定库
- [Lua 5.4](https://www.lua.org/) - 脚本语言

> **注意：** 所有依赖项会在构建时通过 CMake FetchContent 自动下载。

## 构建指南

### 前置要求

- CMake 3.16+
- C++17 兼容编译器 (GCC 8+, Clang 7+, MSVC 2019+)
- Ninja（推荐）或 Make

**Linux 额外依赖包：**
```bash
# Debian/Ubuntu
sudo apt install build-essential cmake ninja-build libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev

# Fedora
sudo dnf install gcc-c++ cmake ninja-build libX11-devel libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel mesa-libGL-devel

# Arch
sudo pacman -S base-devel cmake ninja libx11 libxrandr libxinerama libxcursor libxi mesa
```

### 构建命令

**Linux：**
```bash
# 配置（Debug）
cmake --preset linux-debug

# 构建
cmake --build --preset linux-debug

# 或者 Release 构建
cmake --preset linux-release
cmake --build --preset linux-release
```

**Windows（使用 Ninja）：**
```bash
cmake --preset windows-debug
cmake --build --preset windows-debug
```

**Windows（使用 Visual Studio）：**
```bash
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
```

## License

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件。
