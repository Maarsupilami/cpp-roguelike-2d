#include "map.h"

Map::Map() {
    // Fill border cells with Wall, everything else with Floor.
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            tiles[i][j] = (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                ? TileType::Wall : TileType::Floor;
        }
    }
}

TileType Map::getTile(int row, int col) const {
    return tiles[row][col];
}

bool Map::isWalkable(int row, int col) const {
    return getTile(row, col) == TileType::Floor;
}