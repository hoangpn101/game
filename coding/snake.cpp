#include "snake.h"
#include <cmath>
#include <iostream>

Snake::Snake()
{
}

void Snake::addNode(Node n)
{
    nodes.push_front(n);
}

void Snake::move(Node n)
{
    nodes.push_front(n);
    nodes.pop_back();
}

void Snake::render(sf::RenderWindow &window, int offsetx, int offsety, int cellSize)
{
    sf::CircleShape circle(cellSize / 2 - 1);
    circle.setFillColor(sf::Color( 77, 0, 7 ));
    for (const Node& n : nodes) {
        circle.setPosition(sf::Vector2f(
            offsetx + n.col * cellSize,
            offsety + n.row * cellSize
        ));
        window.draw(circle);
    }

    circle.setRadius(3);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(sf::Vector2f(
        offsetx + nodes.front().col * cellSize + cellSize / 2 - 8,
        offsety + nodes.front().row * cellSize + cellSize / 2 - 3
    ));
    window.draw(circle);

    circle.setRadius(3);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(sf::Vector2f(
        offsetx + nodes.front().col * cellSize + cellSize / 2 + 2,
        offsety + nodes.front().row * cellSize + cellSize / 2 - 3
    ));
    window.draw(circle);
}

Node Snake::step(float dt)
{
    timeSinceLastUpdate += dt;
    if (timeSinceLastUpdate < stepInterval)
        return Node(-1, -1);
    timeSinceLastUpdate = 0;
    Node front = nodes.front();
    switch (direction)
    {
    case UP: front.row--;
        break;
    case DOWN: front.row++;
        break;
    case LEFT: front.col--;
        break;
    case RIGHT: front.col++;
        break;
    }
    return front;
}

void Snake::setDirection(Direction d)
{
    if (direction == UP && d == DOWN) return;
    if (direction == DOWN && d == UP) return;
    if (direction == LEFT && d == RIGHT) return;
    if (direction == RIGHT && d == LEFT) return;
    direction = d;
}

bool Snake::collideSelf(Node n)
{
    Node back = nodes.back();
    if (n.row == back.row && n.col == back.col) return false;
    for (const Node& p : nodes) {
        if (p.row == n.row && p.col == n.col) return true;
    }
    return false;
}

void Snake::increaseSpeed()
{
    float factor = exp(1.0/50 * (log(0.01)-log(0.2)));
    stepInterval *= factor;
    std::cout << stepInterval << std::endl;
}
