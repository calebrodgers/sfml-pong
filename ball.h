#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace sf;

class Ball
{
private:
    CircleShape *body = new CircleShape();
    Vector2f velocity;
    float _speed;
    int timeout = 1;

public:
    Ball(int radius, int pos_x, int pos_y, float speed)
    {
        body->setRadius(radius);
        body->setOrigin(radius, radius);
        body->setPosition(Vector2f(pos_x, pos_y));

        _speed = speed;
        int angle = rand() % 1000;
        velocity = Vector2f(_speed * cos(angle * 6.28 / 1000), _speed * sin(angle * 6.28 / 1000));
        // velocity = Vector2f(-1, 0);
    }

    void reset(Vector2f position)
    {
        timeout = 1;

        body->setPosition(position);

        int angle = rand() % 1000;
        velocity = Vector2f(_speed * cos(angle * 6.28 / 1000), _speed * sin(angle * 6.28 / 1000));
    }

    void update(Vector2u winSize, Scoreboard *scoreboard)
    {
        if (body->getPosition().y + body->getRadius() < 0 || body->getPosition().y + body->getRadius() > winSize.y)
        {
            velocity.y = -velocity.y;
        }

        if (body->getPosition().x + body->getRadius() < 0)
        {
            reset(Vector2f(winSize.x / 2, winSize.y / 2));
            scoreboard->incrementScore(1);
        }

        if (body->getPosition().x + body->getRadius() > winSize.x)
        {
            reset(Vector2f(winSize.x / 2, winSize.y / 2));
            scoreboard->incrementScore(0);
        }

        if (timeout == 0)
        {
            body->move(velocity);
        }
        else if (timeout > 1000)
        {
            timeout = 0;
        }
        else
        {
            timeout++;
        }
    }

    int getRadius()
    {
        return body->getRadius();
    }

    Vector2f getPosition()
    {
        return body->getPosition();
    }

    void collide()
    {
        velocity.x = -velocity.x;
    }

    void
    draw(RenderWindow *window)
    {
        window->draw(*body);
    }
};