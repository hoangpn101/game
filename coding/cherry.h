#ifndef __CHERRY_H
#define __CHERRY_H

#include <SFML/Graphics.hpp>

class Cherry
{
    int row, col;
public:
    Cherry(int row = -1, int col = -1);
    int getRow() const { return row; }
    int getCol() const { return col; }

    void render(sf::RenderWindow& window, int offsetx, int offsety, int cellSize);
};

#endif