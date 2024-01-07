#include <SFML/Graphics.hpp>

class Paddle {
   public:
    float speed;
    float size;
    bool player_one;
    void Init();
    ~Paddle();
};
