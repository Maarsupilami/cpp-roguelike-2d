#include "render.h"
#include <stdexcept>

Render::Render(sf::RenderWindow& window) : window_(window) {
    if (!font_.openFromFile("../assets/fonts/PressStart2P-Regular.ttf"))
        throw std::runtime_error("Failed to load font: PressStart2P-Regular.ttf");
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
    player_.setFillColor(sf::Color::Magenta);
    player_.setPosition(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE));
    window_.draw(player_);
}

void Render::drawHud(int hp) {
    sf::Text text(font_, "HP: " + std::to_string(hp), 16);
    text.setPosition({10.f, 10.f});
    text.setFillColor(sf::Color::Red);
    window_.draw(text);
}
