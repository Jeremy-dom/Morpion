#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "main.h"
#include "plateau.h"

int main(int, char**){
    int tourDuJoueur = 1;
    int winner = 0;
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

    std::string sInfo("Au tour du Joueur 1");
    sf::Text info(font);
    info.setString(sInfo); 
    info.setPosition({500, 50});
    window.draw(info);

    window.draw(board.setRestartButton());

    window.draw(board.setRestartText(font));

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
            if(winner == 0)
            {
                if(board.setSymbol(posLeftClick, tourDuJoueur) != -1)
                {
                    winner = board.checkWinner();
                    if(winner != 0)
                    {
                        std::cout << "Joueur "<< winner << " a gagné" << std::endl;
                    }
                    else if(tourDuJoueur == 1)
                    {
                        tourDuJoueur++;
                        sInfo = "Au tour du Joueur 2";
                        info.setString(sInfo); 
                        window.draw(info);
                    }
                    else if(tourDuJoueur == 2)
                    {
                        tourDuJoueur--;
                        sInfo = "Au tour du Joueur 1";
                        info.setString(sInfo); 
                        window.draw(info);
                    }

                }
            }
            else if (board.clickReset(posLeftClick))
            {
                board.resetGame();
                window.clear();
                window.draw(board.getContourPlateau());
                for(int i = 0; i < board.getNbLigne(); i++)
                {
                    window.draw(board.getLignePlateau(i));
                }
                window.draw(board.setRestartButton());
                window.draw(board.setRestartText(font));
                tourDuJoueur = 1;
                winner = 0; 
                sInfo = "Au tour du Joueur 1";
                info.setString(sInfo); 
                window.draw(info);

            }
            
        }

        window.display();
    }
    
    window.close();
    return 0;
}
