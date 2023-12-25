#include <SFML/Graphics.hpp>
#include <iostream>

const unsigned int width = 1080;
const unsigned int height = 720;
using namespace std;

class Ball {
   public:
    float speed;
    sf::Vector2f pos;
    sf::Vector2f velocity;
    sf::CircleShape circle;
    Ball(sf::Vector2f pos, float speed);
    ~Ball();
};

Ball::Ball(sf::Vector2f pos, float speed) {
    this->speed = speed;
    this->pos = pos;
    this->velocity = sf::Vector2f(0.0f, 0.0f);
}

Ball::~Ball() {}

int main() {
    auto window = sf::RenderWindow{{width, height}, "CMake SFML Project"};
    window.setFramerateLimit(60);

    sf::Clock deltaClock;

    sf::Vector2f ball_position(width / 2.f, height / 2.f);

    Ball ball = Ball(ball_position, 5.f);

    while (window.isOpen()) {
        sf::Time deltaTime = deltaClock.restart();
        cout << "dt: " << deltaTime.asMilliseconds() << endl;
        sf::CircleShape circle(50.f);
        ball.circle = circle;
        ball.circle.setFillColor(sf::Color::Green);
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Keyboard events
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::D) {
                    ball.velocity.x += ball.speed * deltaTime.asSeconds();
                }
                if (event.key.code == sf::Keyboard::A) {
                    ball.velocity.x -= ball.speed * deltaTime.asSeconds();
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::D ||
                    event.key.code == sf::Keyboard::A) {
                    ball.velocity.x = 0.f;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                cout << "We clicked a button!" << endl;
            }
        }

        ball.pos.x += ball.velocity.x;
        ball.pos.y += ball.velocity.y;

        ball.circle.setPosition(ball.pos);
        window.clear(sf::Color(23, 23, 23));
        window.draw(ball.circle);
        window.display();
    }
}