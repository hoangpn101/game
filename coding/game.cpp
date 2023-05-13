#include "game.h"
#include <cstdlib>

Game::Game(int nrow, int ncol)
{
    this->nrow = nrow;
    this->ncol = ncol;

    score_font.loadFromFile("res/arial.ttf");

    snake.addNode(Node(11, 9));
    snake.addNode(Node(11, 10));
    snake.addNode(Node(10, 10));

    generate_cherry();
}

void Game::render(sf::RenderWindow &window)
{
    sf::RectangleShape rect(sf::Vector2f(getWidth(), getHeight()));
    rect.setPosition(sf::Vector2f(0, scoreHeight));
    rect.setFillColor(sf::Color( 76, 153, 0 ));
    window.draw(rect);
    cherry.render(window, 0, scoreHeight, cellSize);
    snake.render(window, 0, scoreHeight, cellSize);

    std::string score_string = "Score: ";
    score_string += std::to_string(score);
    sf::Text text(score_string, score_font, 60);
    text.setPosition(sf::Vector2f(0, 0));
    window.draw(text);
}

void Game::generate_cherry()
{
    cherry = Cherry(
        rand() % nrow,
        rand() % ncol
    );
}

void Game::step(float dt)
{
    Node newPos = snake.step(dt);
    if (newPos.row == -1 && newPos.col == -1)
        return;
    if (newPos.row < 0 || newPos.row >= nrow
      || newPos.col < 0 || newPos.col >= ncol)
        exit(0); // game over
    if (newPos.row == cherry.getRow() 
      && newPos.col == cherry.getCol()) {
        snake.addNode(newPos);
        snake.increaseSpeed();
        generate_cherry();
        score++;
    }
    else {
        if (snake.collideSelf(newPos)) 
            exit(0); // game over
        snake.move(newPos);
    }
}

void Game::processEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
            snake.setDirection(Direction::UP);
            break;
        
        case sf::Keyboard::Down:
            snake.setDirection(Direction::DOWN);
            break;

        case sf::Keyboard::Left:
            snake.setDirection(Direction::LEFT);
            break;

        case sf::Keyboard::Right:
            snake.setDirection(Direction::RIGHT);
            break;

        default:
            break;
        }
    }
}
