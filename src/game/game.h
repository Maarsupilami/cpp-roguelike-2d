#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"
#include "map.h"
#include "render.h"

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
        void handleExploreInput(const sf::Event& event);

        // Initialization order matters: window_ must come before renderer_.
        sf::RenderWindow    window_;
        Render              renderer_;
        Map                 map_;
        GameState           state_{GameState::Explore};
        Direction           direction_  = Direction::Down;
        int                 playerRow_ = 1;
        int                 playerCol_ = 1;
};