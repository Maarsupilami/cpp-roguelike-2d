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
                            int maxHp,
                            int enemyRow,
                            int enemyCol);

    private:
        void drawMap(const Map& map);
        void drawPlayer(float pixelX, float pixelY, Direction direction, PlayerState playerState, float moveProgress);
        void drawHud(int hp, int maxHp);
        // Enemy
        void drawEnemy(int row, int col);


        sf::RenderWindow&   window_;
        sf::Font            font_;
        sf::Text            hud_{font_, "", 16};
        // Terrain textures & sprites
        sf::Texture         floorTexture_;
        sf::Sprite          floorSprite_{floorTexture_};
        sf::Texture         wallTexture_;
        sf::Sprite          wallSprite_{wallTexture_};
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
        static constexpr float FRAME_DURATION = 0.15f;
        // Enemy
        sf::Texture         enemyTextureDown_;
        sf::Sprite          enemySprite_{enemyTextureDown_};
        sf::Clock           enemyClock_;
        int                 enemyFrame_ = 0;
        float               enemyFrameTime_ = 0.f;
};