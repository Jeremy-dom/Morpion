// #include <iostream>
#include <SFML/Graphics.hpp>


#include "main.h"

int main(int, char**){
    auto window = sf::RenderWindow{ { WINDOW_L, WINDOW_H }, "Morpion" };
    window.setFramerateLimit(FPS_LIMIT);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}
