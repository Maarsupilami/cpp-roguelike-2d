#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"

class Game {
    public:
        Game();
        void run();
        void handleInput(const sf::Event& event);
        void render();

    private:
        sf::RenderWindow window_;
        // ── Map ───────────────────────────────────────────────────────────────────
        Map map_;
        // ── Shapes (created once, reused every frame) ─────────────────────────────
        sf::RectangleShape tile_{sf::Vector2f(TILE_SIZE, TILE_SIZE)};
        // ── Player state ──────────────────────────────────────────────────────────
        sf::RectangleShape player_{sf::Vector2f(TILE_SIZE, TILE_SIZE)};
        int playerRow_ = 1, playerCol_ = 1;

        void drawMap();
        void drawPlayer();
};