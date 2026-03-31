#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "DungeonRPG");

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
        window.display();
    }
    return 0;
}
