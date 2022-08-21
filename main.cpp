#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "scoreboard.h"
#include "ball.h"
#include "player.h"

using namespace sf;

class Game
{
private:
    RenderWindow *window;
    Scoreboard *scoreboard;
    Ball *ball;
    Player *player1;
    Player *player2;

public:
    Game(int size_x, int size_y, std::string window_name)
    {
        scoreboard = new Scoreboard();
        window = new RenderWindow(VideoMode(size_x, size_y), window_name);
        player1 = new Player(20, 120, 40, size_y / 2 - 120 / 2);
        player2 = new Player(20, 120, size_x - 40 - 20, size_y / 2 - 120 / 2);
        ball = new Ball(10, size_x / 2, size_y / 2, 0.5);
    }
    void run()
    {
        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            window->clear();

            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                player1->move(0.4, window->getSize().y);
            }
            else if (Keyboard::isKeyPressed(Keyboard::W))
            {
                player1->move(-0.4, window->getSize().y);
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                player2->move(0.4, window->getSize().y);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                player2->move(-0.4, window->getSize().y);
            }

            ball->update(window->getSize(), scoreboard);
            ball->draw(window);
            player1->checkCollision(ball, 1);
            player1->draw(window);
            player2->checkCollision(ball, 0);
            player2->draw(window);
            scoreboard->update();
            scoreboard->draw(window);
            window->display();
        }
    }
};

int main()
{
    Game game(1000, 600, "Pong");

    game.run();

    return 0;
}
