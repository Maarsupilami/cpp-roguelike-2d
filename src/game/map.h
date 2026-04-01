#pragma once

// ── Tile types ────────────────────────────────────────────────────────────────
enum class TileType { Floor, Wall };

// ── Map dimensions and rendering constants ────────────────────────────────────
constexpr int COLS      = 20;
constexpr int ROWS      = 15;
constexpr int TILE_SIZE = 32;   // pixels per tile

// ── Map ───────────────────────────────────────────────────────────────────────
// Owns the 2D tile grid. Responsible for initialization and tile queries.
// Rendering and game logic are handled by separate classes.
class Map {
    public:
        Map();  // Fills border with Wall, interior with Floor.

        TileType getTile(int row, int col) const;
        bool     isWalkable(int row, int col) const;

    private:
        TileType tiles[ROWS][COLS];
};
