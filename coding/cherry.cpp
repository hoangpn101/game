#include "cherry.h"

Cherry::Cherry(int row, int col)
{
    this->row = row;
    this->col = col;
}

void Cherry::render(sf::RenderWindow &window, int offsetx, int offsety, int cellSize)
{
  sf::Texture texture;
    texture.loadFromFile("res/cherry.png");

    sf::Sprite cherry(texture);

    cherry.setPosition(sf::Vector2f(
        offsetx + col * cellSize,
        offsety + row * cellSize
    ));

    window.draw(cherry);
}
