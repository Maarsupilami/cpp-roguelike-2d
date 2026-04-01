#include "render.h"
#include <stdexcept>

Render::Render(sf::RenderWindow& window) : window_(window) {
    if (!font_.openFromFile("assets/fonts/PressStart2P-Regular.ttf"))
        throw std::runtime_error("Failed to load font: PressStart2P-Regular.ttf");
    if (!playerTexture_.loadFromFile("assets/Entities/Characters/Body_A/Animations/Idle_Base/Idle_Down-Sheet.png"))
        throw std::runtime_error("Failed to load texture: Idle_Down-Sheet.png");
    playerSprite_.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
}

void Render::renderExplore(const Map& map, int row, int col) {
    window_.clear(sf::Color(20, 20, 20));
    drawMap(map);
    drawPlayer(row, col);
    drawHud(100);
    window_.display();
}

void Render::drawMap(const Map& map) {
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            tile_.setFillColor(!map.isWalkable(r, c)
                ? sf::Color(80, 80, 80)
                : sf::Color(60, 40, 20));
            tile_.setPosition(sf::Vector2f(c * TILE_SIZE, r * TILE_SIZE));
            window_.draw(tile_);
        }
    }
}

void Render::drawPlayer(int row, int col) {
    playerSprite_.setPosition(sf::Vector2f(col * TILE_SIZE - 16.f, row * TILE_SIZE - 16.f));
    window_.draw(playerSprite_);
}

void Render::drawHud(int hp) {
    hud_.setString("HP: " + std::to_string(hp));
    hud_.setPosition({10.f, 10.f});
    hud_.setFillColor(sf::Color::Red);
    window_.draw(hud_);
}
