#include <SFML/Graphics.hpp>

class Ball {
   public:
    float speed;
    sf::Vector2f pos;
    sf::Vector2f velocity;
    sf::CircleShape circle;
    Ball(sf::Vector2f pos, float speed);
    void Update(sf::Time dt);
    void BounceX();
    void BounceY();
    void Init();
    ~Ball();
};
