#include <iostream>
#include <SFML/Graphics.hpp>


#include "main.h"
#include "plateau.h"

int main(int, char**){
    sf::Vector2i localPosition; 
    sf::Vector2f forigin((float)0, (float)0);

    sf::RenderWindow window(sf::VideoMode({ WINDOW_L, WINDOW_H }), "Morpion");
    window.setFramerateLimit(FPS_LIMIT);

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

    // window.draw(text);

    // sf::CircleShape circle(50.f);
    // circle.setOrigin(sf::Vector2f(circle.getRadius()+5.f, circle.getRadius()+5.f));
    // circle.setFillColor(sf::Color(0, 0, 0));
    // circle.setOutlineThickness(5.f);
    // circle.setPosition(forigin);
    // window.draw(circle);

    sf::RectangleShape line1(sf::Vector2f(150, 5));
    line1.setOrigin(sf::Vector2f(line1.getSize().x/2, line1.getSize().y/2));
    line1.rotate(sf::degrees(45));
    line1.setPosition(sf::Vector2f(1000, 500));

    sf::RectangleShape line2(sf::Vector2f(150, 5));
    line2.setOrigin(sf::Vector2f(line2.getSize().x/2, line2.getSize().y/2));
    line2.rotate(sf::degrees(135));
    line2.setPosition(sf::Vector2f(1000, 500));

    // sf::RectangleShape linetab[2];

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


        if(board.getNbCircle() != 0) window.draw(board.getCircle(0));
        // if(line1.getPosition() != forigin) window.draw(line1);
        // if(line2.getPosition() != forigin) window.draw(line2);
        // window.draw(line1);
        // window.draw(line2);

        if (leftClick)
        {


           // posCircle = sf::Vector2f((float)localPosition.x, (float)localPosition.y);
            // board.setCircle(posCircle);
            line1.setPosition(posLeftClick);
            line2.setPosition(posLeftClick);
            window.draw(line1);
            window.draw(line2);
        }

        if(rightClick)
        {
            // on lit la position locale de la souris (relativement à une fenêtre)
            sf::CircleShape circle(50.f);
            circle.setOrigin(forigin);
            circle.setFillColor(sf::Color::Black);
            circle.setOutlineThickness(5.f);
            circle.setPosition(posRightClick);
            circle.setOutlineColor(sf::Color::White);
            window.draw(circle);
        }
        
        window.display();
    }
    
    window.close();
    return 0;
}
