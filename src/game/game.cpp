#include "game.h"

Game::Game()
    :   window_(sf::VideoMode({800, 600}), "DungeonRPG"),
        renderer_(window_),
        playerRow_(1), playerCol_(1)
{};

void Game::run() {
    while (window_.isOpen()) {
        while (const std::optional event = window_.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window_.close();
            switch (state_) {
                case GameState::Explore:
                    handleExploreInput(*event);
                    break;
            }
        }
        switch (state_) {
            case GameState::Explore:
                renderer_.renderExplore(map_, playerRow_, playerCol_);
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