#include <iostream>
#include <SFML/Graphics.hpp>
#include "game/map.h"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "DungeonRPG");
    TileType map[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            map[i][j] = (i == 0 || i == (ROWS - 1) || j == 0 || j == (COLS - 1))
                ? TileType::Wall : TileType::Floor;
        }
    }

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (auto* e = event->getIf<sf::Event::KeyPressed>()) {
                switch (e->code) {
                    case sf::Keyboard::Key::W:
                        std::cout << "UP!" << std::endl;
                        break;
                    case sf::Keyboard::Key::S:
                        std::cout << "DOWN!" << std::endl;
                        break;
                    case sf::Keyboard::Key::A:
                        std::cout << "LEFT!" << std::endl;
                        break;
                    case sf::Keyboard::Key::D:
                        std::cout << "RIGHT!" << std::endl;
                        break;
                    default:
                        std::cout << "A KEY IS PRESSED!" << std::endl;
                        break;
                }
            }
        }
        window.clear(sf::Color(20, 20, 20));
        sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                tile.setFillColor(map[r][c] == TileType::Wall
                    ? sf::Color(80, 80, 80)
                    : sf::Color(60, 40, 20));
                tile.setPosition(sf::Vector2f(c * TILE_SIZE, r * TILE_SIZE));
                window.draw(tile);
            }
        }
        window.display();
    }
    return 0;
}
