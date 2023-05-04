#ifndef __SNAKE_H
#define __SNAKE_H

#include <SFML/Graphics.hpp>
#include <list>

struct Node
{
    int row, col;
    Node(int row, int col) {
        this->row = row;
        this->col = col;
    }
};

enum Direction {
    UP=0, DOWN, LEFT, RIGHT
};

class Snake
{
    std::list<Node> nodes;
    float timeSinceLastUpdate = 0;
    float stepInterval = 0.2;
    Direction direction = RIGHT;
public:
    Snake();
    
    void addNode(Node n);
    void move(Node n);
    void render(sf::RenderWindow& window, int offsetx, int offsety, int cellSize);

    Node step(float dt);
    void setDirection(Direction d);

    bool collideSelf(Node n);
    void increaseSpeed();
};

#endif