#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"

// ── Game ──────────────────────────────────────────────────────────────────────
// Top-level class. Owns the window, runs the game loop, and delegates
// input handling and rendering to private methods.
class Game {
public:
    Game();
    void run();

private:
    void handleInput(const sf::Event& event);
    void render();
    void drawMap();
    void drawPlayer();

    sf::RenderWindow window_;
    Map              map_;
    sf::RectangleShape tile_{sf::Vector2f(TILE_SIZE, TILE_SIZE)};
    sf::RectangleShape player_{sf::Vector2f(TILE_SIZE, TILE_SIZE)};
    int playerRow_ = 1;
    int playerCol_ = 1;
};