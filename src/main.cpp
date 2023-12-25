#include <SFML/Graphics.hpp>
#include <iostream>

const unsigned int width = 1080;
const unsigned int height = 720;
using namespace std;

int main() {
    auto window = sf::RenderWindow{{width, height}, "CMake SFML Project"};
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Keyboard events
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                cout << "We clicked a button!" << endl;
            }
        }

        window.clear(sf::Color(23, 23, 23));
        // * Create a green circle
        sf::CircleShape ball(50.f);
        ball.setFillColor(sf::Color::Green);
        ball.setPosition(width / 2.f, height / 2.f);
        window.draw(ball);
        window.display();
    }
}