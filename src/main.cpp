#include <iostream>
#include <SFML/Graphics.hpp>
#include "game/map.h"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "DungeonRPG");

    // ── Map ───────────────────────────────────────────────────────────────────
    Map map;
    // ── Shapes (created once, reused every frame) ─────────────────────────────
    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    sf::RectangleShape player(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    player.setFillColor(sf::Color::Magenta);

    // ── Player state ──────────────────────────────────────────────────────────
    int playerCol = 1;
    int playerRow = 1;

    // ── Game loop ─────────────────────────────────────────────────────────────
    while (window.isOpen()) {

        // — Input ——————————————————————————————————————————————————————————————
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (auto* e = event->getIf<sf::Event::KeyPressed>()) {
                int newRow = playerRow;
                int newCol = playerCol;

                switch (e->code) {
                    case sf::Keyboard::Key::W: newRow -= 1; break;
                    case sf::Keyboard::Key::S: newRow += 1; break;
                    case sf::Keyboard::Key::A: newCol -= 1; break;
                    case sf::Keyboard::Key::D: newCol += 1; break;
                    default:
                        std::cout << "A KEY IS PRESSED!" << std::endl;
                        break;
                }

                // Only move if the target cell is walkable.
                if (map.isWalkable(newRow, newCol)) {
                    playerRow = newRow;
                    playerCol = newCol;
                }
            }
        }

        // — Render ——————————————————————————————————————————————————————————————
        window.clear(sf::Color(20, 20, 20));

        // Draw tilemap.
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                tile.setFillColor(!map.isWalkable(r, c)
                    ? sf::Color(80, 80, 80)
                    : sf::Color(60, 40, 20));
                tile.setPosition(sf::Vector2f(c * TILE_SIZE, r * TILE_SIZE));
                window.draw(tile);
            }
        }

        // Draw player on top of tilemap.
        player.setPosition(sf::Vector2f(playerCol * TILE_SIZE, playerRow * TILE_SIZE));
        window.draw(player);

        window.display();
    }

    return 0;
}
