# Dungeon RPG 2D

A 2D graphical dungeon crawler built in C++23 with SFML.
Continuation of [cpp-roguelike-cli](https://github.com/Maarsupilami/cpp-roguelike-cli).

> **Status: in progress.**

## Planned features

- SFML window with tile-based rendering
- Sprite animations for player and enemies
- Mouse/keyboard input replacing CLI menus
- Same core game logic as the CLI version (Character, Player, Enemy, Item hierarchy)

## Build

> Requirements and build instructions will be added as the project progresses.

Requires CMake 3.28+, GCC 15+, and SFML 2.6+.

## From the CLI version

The `src/core/` module (characters, enemies, items, loot system) is carried over
from the CLI version unchanged. The `game/` layer is rewritten for SFML.
