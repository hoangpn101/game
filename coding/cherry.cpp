#include "cherry.h"

Cherry::Cherry(int row, int col)
{
    this->row = row;
    this->col = col;
}

void Cherry::render(sf::RenderWindow &window, int offsetx, int offsety, int cellSize)
{
    sf::CircleShape circle(cellSize / 2);
    circle.setPosition(sf::Vector2f(
        offsetx + col * cellSize,
        offsety + row * cellSize
    ));
    circle.setFillColor(sf::Color::Red);
    window.draw(circle);
}
