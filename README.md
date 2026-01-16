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

- **Fully Declarative** — Game as Data. Describe what the game state should be, not how to process it.
- **Single File Architecture** — All configurations, entity definitions, and update logic exist in **one** file. Easy to share, easy to version control.
- **Thin Host** — Built on a **C++** and **Raylib** backend, interacting with **Lua via Sol2**.
- **Prototype First** — Designed for **Game Jams** and rapid gameplay verification. Write games like you write configuration files.

## Dependencies

- [Raylib](https://www.raylib.com/) - Simple and easy-to-use graphics library
- [Sol2](https://github.com/ThePhD/sol2) - C++ ↔ Lua binding library

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
