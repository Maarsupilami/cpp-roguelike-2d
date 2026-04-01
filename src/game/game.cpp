#include "game.h"

Game::Game()
    : window_(sf::VideoMode({800, 600}), "DungeonRPG"),
      playerRow_(1), playerCol_(1)
{};

void Game::run() {
    while (window_.isOpen()) {
        while (const std::optional event = window_.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window_.close();
            switch (gameState_) {
                case GameState::EXPLORE:
                    handleExploreInput(*event);
                    break;
            }
        }
        switch (gameState_) {
            case GameState::EXPLORE:
                renderExplore();
                break;
        }
    }
}

void Game::handleExploreInput(const sf::Event& event) {
    if (auto* e = event.getIf<sf::Event::KeyPressed>()) {
        int newRow = playerRow_;
        int newCol = playerCol_;

        switch (e->code) {
            case sf::Keyboard::Key::W: newRow -= 1; break;
            case sf::Keyboard::Key::S: newRow += 1; break;
            case sf::Keyboard::Key::A: newCol -= 1; break;
            case sf::Keyboard::Key::D: newCol += 1; break;
            default:
                break;
        }

        // Only move if the target cell is walkable.
        if (map_.isWalkable(newRow, newCol)) {
            playerRow_ = newRow;
            playerCol_ = newCol;
        }
    }
}

void Game::renderExplore() {
    window_.clear(sf::Color(20, 20, 20));
    drawMap();
    drawPlayer();
    window_.display();
}

void Game::drawMap() {
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            tile_.setFillColor(!map_.isWalkable(r, c)
                ? sf::Color(80, 80, 80)
                : sf::Color(60, 40, 20));
            tile_.setPosition(sf::Vector2f(c * TILE_SIZE, r * TILE_SIZE));
            window_.draw(tile_);
        }
    }
}

void Game::drawPlayer() {
    player_.setFillColor(sf::Color::Magenta);
    player_.setPosition(sf::Vector2f(playerCol_ * TILE_SIZE, playerRow_ * TILE_SIZE));
    window_.draw(player_);
}