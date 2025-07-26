#include <iostream>
#include <SFML/Graphics.hpp>

#include "main.h"
#include "plateau.h"

int main(int, char**){
    sf::Vector2i localPosition; 
    sf::Vector2f forigin((float)0, (float)0);

    sf::RenderWindow window(sf::VideoMode({ WINDOW_L, WINDOW_H }), "Morpion");
    window.setFramerateLimit(FPS_LIMIT);

    window.setPosition(sf::Vector2i({3840, 0}));

    Plateau board(window.getSize());

    sf::Font font;
    if (!font.openFromFile("/mnt/c/Users/commu/Documents/Projet/CPP/Morpion/font/arial.ttf"))
    {
        std::cerr << "Error on the font arial.ttf" << std::endl;
    }
    // choix de la police à utiliser
    sf::Text text(font);

    // choix de la chaîne de caractères à afficher
    text.setString("Hello world");

    text.setPosition(sf::Vector2f({(float)0, (float)0}));

    sf::Vector2f posCircle;
    bool leftClick;
    sf::Vector2f posLeftClick;
    bool rightClick;
    sf::Vector2f posRightClick;

        // window.clear();
    window.draw(board.getContourPlateau());
    for(int i = 0; i < board.getNbLigne(); i++)
    {
        window.draw(board.getLignePlateau(i));
    }

    while (window.isOpen())
    {
        //Geston des events (clique, appuie de touche, ...)
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    leftClick = true;
                    posLeftClick.x = mouseButtonPressed->position.x;
                    posLeftClick.y = mouseButtonPressed->position.y;
                }
                else if (mouseButtonPressed->button == sf::Mouse::Button::Right)
                {
                    rightClick = true;
                    posRightClick.x = mouseButtonPressed->position.x;
                    posRightClick.y = mouseButtonPressed->position.y;
                }          
            }
            else
            {
                leftClick = false;
                rightClick = false;
            }
        }


        for(int i = 0; i < board.getNbCircle(); i++) 
            window.draw(board.getCircle(i));

        for(int i = 0; i < board.getNbCross(); i++) 
        {
            window.draw(board.getCrossLine1(i));
            window.draw(board.getCrossLine2(i));

        }

        if (leftClick)
        {
            if(board.setCross(posLeftClick) == -1)
                std::cout << "Clic en dehors du plateau" << std::endl;
        }

        if(rightClick)
        {
            if(board.setCircle(posRightClick) == -1)
                std::cout << "Clic en dehors du plateau" << std::endl;
        }
        
        window.display();
    }
    
    window.close();
    return 0;
}
