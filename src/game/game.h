#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"
#include "map.h"
#include "player_state.h"
#include "render.h"
#include "classes/warrior.h"
#include "enemies/goblin.h"

// ── GameState ─────────────────────────────────────────────────────────────────
enum class GameState { Explore };

// ── Game ──────────────────────────────────────────────────────────────────────
// Top-level class. Owns the window and game state, runs the main loop, and
// delegates input and rendering based on the active GameState.
class Game {
    public:
        Game();
        void run();

    private:
        void tryMove(Direction dir);

        // Movement speed in tiles per second.
        static constexpr float MOVE_SPEED = 5.f;

        // Initialization order matters: window_ must come before renderer_.
        sf::RenderWindow    window_;
        Render              renderer_;
        Map                 map_;
        GameState           state_{GameState::Explore};
        Direction           direction_  = Direction::Down;
        PlayerState         playerState_ = PlayerState::Idle;
        sf::Clock           deltaClock_;

        // Logical grid position (destination tile).
        int     playerRow_ = 1;
        int     playerCol_ = 1;

        // Movement interpolation state.
        Direction   pendingDir_     = Direction::Down;
        bool        isMoving_       = false;
        float       moveProgress_   = 0.f;   // 0.0 = at start, 1.0 = at destination
        int         startRow_       = 1;
        int         startCol_       = 1;

        // Pixel position passed to the renderer.
        float   pixelX_ = 1.f * TILE_SIZE;
        float   pixelY_ = 1.f * TILE_SIZE;

        // Character related.
        Warrior player_{"Minh"};

        // Enemy related.
        Goblin  enemy_{"Orc"};
        int enemyRow_ = 5;
        int enemyCol_ = 5;
};
