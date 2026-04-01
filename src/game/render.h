#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"
#include "map.h"

// ── Renderer ──────────────────────────────────────────────────────────────────
// Stateless drawing layer. Holds reusable SFML objects (shapes, font) and
// exposes one render method per GameState. Does not own the window.
class Render {
    public:
        explicit Render(sf::RenderWindow& window);

        void renderExplore(const Map& map, int row, int col, Direction direction);

    private:
        void drawMap(const Map& map);
        void drawPlayer(int row, int col, Direction direction);
        void drawHud(int hp);

        sf::RenderWindow&   window_;
        sf::Font            font_;
        sf::Text            hud_{font_, "", 16};
        sf::RectangleShape  tile_{sf::Vector2f(TILE_SIZE, TILE_SIZE)};
        sf::Texture         playerTextureDown_;
        sf::Texture         playerTextureUp_;
        sf::Texture         playerTextureSide_;
        sf::Sprite          playerSprite_{playerTextureDown_};
        sf::Clock           animClock_;
        int                 currentFrame_ = 0;
        float               frameTime_ = 0.f;
        const int           FRAME_COUNT = 4;
        const float         FRAME_DURATION = 0.15f;
};