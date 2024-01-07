#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"

const unsigned int width = 1080;
const unsigned int height = 720;

using namespace std;

int main() {
    auto window = sf::RenderWindow{{width, height}, "CMake SFML Project"};
    window.setFramerateLimit(60);

    sf::Clock deltaClock;

    sf::Vector2f ball_position(width / 2.f, height / 2.f);

    Paddle player_1, player2;
    // TODO Start creating the paddles!!

    Ball ball = Ball(ball_position, 500.f);
    ball.Init();

    while (window.isOpen()) {
        sf::Time deltaTime = deltaClock.restart();
        cout << "dt: " << deltaTime.asMilliseconds() << endl;
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
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                cout << "mouse_pos: (" << (int)mouse_position.x << ", "
                     << (int)mouse_position.y << ")" << endl;
            }
        }

        ball.Update(deltaTime);
        // ball.circle.setPosition(ball.pos);
        window.clear(sf::Color(23, 23, 23));
        window.draw(ball.circle);
        window.display();
    }
}