#include <SFML/Graphics.hpp>
#include <iostream>

#include "game.h"

int main()
{
    Game game(20, 20);
    sf::RenderWindow window(sf::VideoMode(game.getWindowWidth(), game.getWindowHeight()), "SNAKE");
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // process event
            game.processEvent(event);
        }
        // update game state, make a step
        float dt = clock.restart().asSeconds();
        game.step(dt);

        window.clear();
        // drawing code
        game.render(window);

        window.display();
    }
    return 0;
}
