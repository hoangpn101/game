#ifndef __GAME_H
#define __GAME_H

#include <SFML/Graphics.hpp>
#include "cherry.h"
#include "snake.h"

class Game
{
    int nrow, ncol;
    int cellSize = 40;
    Cherry cherry;
    Snake snake;

    sf::Font score_font;
    
    int score = 0;
    int scoreHeight = 100;
public:
    Game(int nrow, int ncol);

    int getWindowWidth() const { return getWidth(); }
    int getWindowHeight() const { return getHeight() + scoreHeight; }
    int getWidth() const { return ncol*cellSize; }
    int getHeight() const { return nrow*cellSize; }

    void render(sf::RenderWindow& window);
    void generate_cherry();

    void step(float dt);
    void processEvent(sf::Event& event);
};

#endif