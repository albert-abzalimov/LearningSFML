#include "ball.hpp"
#include <iostream>

Ball::Ball(sf::Vector2f pos, float speed) {
    this->speed = speed;
    this->pos = pos;
}

void Ball::Init() {
    sf::CircleShape circle(50.f);
    this->circle = circle;
    this->velocity.x = this->speed;
    this->velocity.y = this->speed;
    this->circle.setFillColor(sf::Color::Green);
}
void Ball::Update(sf::Time dt) {
    this->pos.x += this->velocity.x * dt.asSeconds();
    this->pos.y += this->velocity.y * dt.asSeconds();

    circle.setPosition(pos);
    // since walls are only going to be orthogonal... this will be really easy
    if (pos.x <= 0.0f || pos.x + circle.getRadius() * 2.f >= 1080.0f) {
        BounceX();
    }
    if (pos.y <= 0.0f || pos.y + circle.getRadius() * 2.f >= 720.0f) {
        BounceY();
    }
}

void Ball::BounceX() {
    this->velocity.x = -this->velocity.x;
}
void Ball::BounceY() {
    this->velocity.y = -this->velocity.y;
}

Ball::~Ball() {}