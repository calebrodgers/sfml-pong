#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace sf;

class Scoreboard
{
private:
    int scores[2] = {0, 0};
    Font *font = new Font();
    Text *text = new Text();

public:
    Scoreboard()
    {
        font->loadFromFile("Silkscreen-Regular.ttf");
        text->setFont(*font);
        text->setString("0 | 0");
        text->setPosition(Vector2f(10, 10));
        text->setCharacterSize(48);
    }

    void incrementScore(int idx)
    {
        scores[idx]++;
    }

    int getScore(int idx)
    {
        return scores[idx];
    }
    void update()
    {
        std::string scoreString = std::to_string(scores[0]);
        scoreString.append(" | ");
        scoreString.append(std::to_string(scores[1]));
        text->setString(scoreString);
    }
    void draw(RenderWindow *window)
    {
        window->draw(*text);
    }
};