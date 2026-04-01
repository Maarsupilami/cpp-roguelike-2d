#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"
#include "map.h"
#include "player_state.h"

// ── Renderer ──────────────────────────────────────────────────────────────────
// Stateless drawing layer. Holds reusable SFML objects (shapes, font) and
// exposes one render method per GameState. Does not own the window.
class Render {
    public:
        explicit Render(sf::RenderWindow& window);

        void renderExplore(const Map& map,
                            float pixelX,
                            float pixelY,
                            Direction direction,
                            PlayerState playerState,
                            float moveProgress,
                            int hp,
                            int maxHp);

    private:
        void drawMap(const Map& map);
        void drawPlayer(float pixelX, float pixelY, Direction direction, PlayerState playerState, float moveProgress);
        void drawHud(int hp, int maxHp);

        sf::RenderWindow&   window_;
        sf::Font            font_;
        sf::Text            hud_{font_, "", 16};
        sf::RectangleShape  tile_{sf::Vector2f(TILE_SIZE, TILE_SIZE)};
        sf::Texture         playerTextureDown_;
        sf::Texture         playerTextureUp_;
        sf::Texture         playerTextureSide_;
        sf::Texture         playerTextureWalkingDown_;
        sf::Texture         playerTextureWalkingUp_;
        sf::Texture         playerTextureWalkingSide_;
        sf::Sprite          playerSprite_{playerTextureDown_};
        sf::Clock           animClock_;
        PlayerState         prevState_ = PlayerState::Idle;
        Direction           prevDir_   = Direction::Down;
        int                 currentFrame_ = 0;
        float               frameTime_ = 0.f;
        const float         FRAME_DURATION = 0.15f;
};