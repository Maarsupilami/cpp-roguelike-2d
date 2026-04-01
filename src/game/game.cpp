#include "game.h"

Game::Game()
    :   window_(sf::VideoMode({800, 600}), "Chronicles of Minh"),
        renderer_(window_)
{};

void Game::run() {
    while (window_.isOpen()) {
        float dt = deltaClock_.restart().asSeconds();

        // ── Input ─────────────────────────────────────────────────────────────
        while (const std::optional event = window_.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window_.close();
            else if (auto* e = event->getIf<sf::Event::KeyPressed>()) {
                if      (e->code == sf::Keyboard::Key::W) pendingDir_ = Direction::Up;
                else if (e->code == sf::Keyboard::Key::S) pendingDir_ = Direction::Down;
                else if (e->code == sf::Keyboard::Key::A) pendingDir_ = Direction::Right;
                else if (e->code == sf::Keyboard::Key::D) pendingDir_ = Direction::Left;
            } else if (auto* e = event->getIf<sf::Event::KeyReleased>()) {
                // Revert to whichever movement key is still held.
                if      (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) pendingDir_ = Direction::Up;
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) pendingDir_ = Direction::Down;
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) pendingDir_ = Direction::Right;
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) pendingDir_ = Direction::Left;
            }
        }

        // Only accept new input when the previous move is complete.
        if (!isMoving_) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                tryMove(pendingDir_);
            }
        }

        // ── Movement interpolation ────────────────────────────────────────────
        if (isMoving_) {
            moveProgress_ += MOVE_SPEED * dt;
            if (moveProgress_ >= 1.f) {
                moveProgress_ = 1.f;
                isMoving_ = false;
            }
            pixelX_ = (startCol_ + (playerCol_ - startCol_) * moveProgress_) * TILE_SIZE;
            pixelY_ = (startRow_ + (playerRow_ - startRow_) * moveProgress_) * TILE_SIZE;
        }

        // ── Animation state ───────────────────────────────────────────────────
        playerState_ = isMoving_ ? PlayerState::Walking : PlayerState::Idle;

        // ── Render ────────────────────────────────────────────────────────────
        switch (state_) {
            case GameState::Explore:
                renderer_.renderExplore(map_,
                                        pixelX_,
                                        pixelY_,
                                        direction_,
                                        playerState_,
                                        moveProgress_,
                                        player_.getHp(),
                                        player_.getMaxHp(),
                                        enemyRow_,
                                        enemyCol_);
                break;
        }
    }
}

void Game::tryMove(Direction dir) {
    int dRow = 0, dCol = 0;

    // Update facing direction regardless of walkability.
    if      (dir == Direction::Up)    dRow = -1;
    else if (dir == Direction::Down)  dRow =  1;
    else if (dir == Direction::Right) dCol = -1;
    else if (dir == Direction::Left)  dCol =  1;

    direction_ = dir;

    int newRow = playerRow_ + dRow;
    int newCol = playerCol_ + dCol;
    if (!map_.isWalkable(newRow, newCol)) return;

    // Start movement interpolation.
    startRow_     = playerRow_;
    startCol_     = playerCol_;
    playerRow_    = newRow;
    playerCol_    = newCol;
    moveProgress_ = 0.f;
    isMoving_     = true;
}
