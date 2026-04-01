# Chronicles of Minh

A 2D tile-based dungeon crawler built in C++23 with SFML 3.
Continuation of [cpp-roguelike-cli](https://github.com/Maarsupilami/cpp-roguelike-cli).

> **Status: in progress.**

---

## Features

- SFML 3 window with tile-based map rendering
- Smooth tile-to-tile player movement with progress-synced animation
- Directional sprite sheets (Up / Down / Left / Right) with Idle and Walk states
- Event-driven keyboard input (no `std::cin`)
- HUD text rendering with pixel font
- Core game logic (Character, Player, Enemy, Item hierarchy) carried over from the CLI version unchanged
- 39 Google Test unit tests covering core logic (no SFML dependency in tests)

---

## Tech stack

| | |
|---|---|
| Language | C++23 |
| Compiler | GCC 15+ |
| Build system | CMake 4.2+ |
| Graphics | SFML 3.0 |
| Testing | Google Test (via FetchContent) |

---

## Project structure

```
src/
  main.cpp                  — entry point
  core/                     — ported from CLI version (no SFML dependency)
    character.h / player.h / enemy.h
    item.h / items/
    combat.h / combat.cpp
    loot_table.h
    game_constants.h
  game/                     — SFML layer
    game.h / game.cpp       — main loop, input, movement interpolation
    map.h / map.cpp         — tile grid, walkability queries
    render.h / render.cpp   — all drawing logic
    direction.h             — Direction enum (Up/Down/Left/Right)
    player_state.h          — PlayerState enum (Idle/Walking)
assets/
  fonts/                    — PressStart2P pixel font
  Entities/Characters/      — directional sprite sheets (64x64, 4–6 frames)
tests/
  main_test.cpp             — Google Test suite for core logic
```

---

## Build

### Requirements

- CMake 4.2+
- GCC 15+
- SFML 3.0 (`sudo pacman -S sfml` on Arch)

### Steps

```bash
cmake -S . -B build
cmake --build build
./build/dungeon
```

### Tests

```bash
cd build && ctest
```

---

## Controls

| Key | Action |
|-----|--------|
| W | Move up |
| S | Move down |
| A | Move left |
| D | Move right |

---

## From the CLI version

The `src/core/` module is carried over from [cpp-roguelike-cli](https://github.com/Maarsupilami/cpp-roguelike-cli) unchanged:

- `Character` → `Player` / `Enemy` with subclasses (Warrior, Mage, Rogue / Goblin, Skeleton, Troll, GoblinChief, StoneGolem, DarkNecromancer)
- Abstract `Item` hierarchy (HealthPotion, IronSword, MagicScroll)
- `LootTable` with `std::function` factories
- `executeAttack()` extracted for testability
- `game_constants.h` with `inline constexpr` stat structs

The `src/game/` layer is a complete rewrite for SFML.
