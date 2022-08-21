#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "player.h"

using namespace sf;

class Game
{
private:
    RenderWindow *window;
    Player *player1;
    Player *player2;

public:
    Game(int size_x, int size_y, std::string window_name)
    {
        window = new RenderWindow(VideoMode(size_x, size_y), window_name);
        player1 = new Player(20, 120, 20, 20);
        player2 = new Player(20, 120, size_x - 20 - 20, 20);
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

            player1->draw(window);
            player2->draw(window);
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
