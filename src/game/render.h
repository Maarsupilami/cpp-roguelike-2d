#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"

// ── Renderer ──────────────────────────────────────────────────────────────────
// Stateless drawing layer. Holds reusable SFML objects (shapes, font) and
// exposes one render method per GameState. Does not own the window.
class Render {
    public:
        explicit Render(sf::RenderWindow& window);

        void renderExplore(const Map& map, int row, int col);

    private:
        void drawMap(const Map& map);
        void drawPlayer(int row, int col);
        void drawHud(int hp);

        sf::RenderWindow&   window_;
        sf::Font            font_;
        sf::Text            hud_{font_, "", 16};
        sf::RectangleShape  tile_{sf::Vector2f(TILE_SIZE, TILE_SIZE)};
        sf::Texture         playerTexture_;
        sf::Sprite          playerSprite_{playerTexture_};
};