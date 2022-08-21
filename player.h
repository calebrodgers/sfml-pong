#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace sf;

class Player
{
private:
    RectangleShape *body = new RectangleShape();

public:
    Player(int size_x, int size_y, int x_offset, int y_offset)
    {
        body->setSize(Vector2f(size_x, size_y));
        body->setPosition(Vector2f(x_offset, y_offset));
    }
    void move(float amount, int height)
    {
        if (amount < 0 && body->getPosition().y > 0)
        {
            body->move(Vector2f(0, amount));
        }
        else if (amount > 0 && body->getPosition().y + body->getSize().y < height)
        {
            body->move(Vector2f(0, amount));
        }
    }
    void draw(RenderWindow *window)
    {
        window->draw(*body);
    }
};