#include <iostream>
#include <SFML/Graphics.hpp>


#include "main.h"
#include "plateau.h"

int main(int, char**){
    sf::Vector2i localPosition; 
    sf::Vector2f forigin((float)0, (float)0);

    auto window = sf::RenderWindow{ { WINDOW_L, WINDOW_H }, "Morpion" };
    window.setFramerateLimit(FPS_LIMIT);


    Plateau board(window.getSize());

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("/mnt/c/Users/commu/Documents/Projet/CPP/Morpion/font/arial.ttf"))
    {
        std::cerr << "Erreur on the font arial.ttf" << std::endl;
    }
    // choix de la police à utiliser
    text.setFont(font); // font est un sf::Font

    // choix de la chaîne de caractères à afficher
    text.setString("Hello world");

    text.setPosition((float)0, (float)0);

    sf::CircleShape circle(50.f);
    circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
    circle.setFillColor(sf::Color(0, 0, 0));
    circle.setOutlineThickness(5.f);
    circle.setPosition(forigin);

    sf::RectangleShape line1(sf::Vector2f(150, 5));
    line1.setOrigin(sf::Vector2f(line1.getSize().x/2, line1.getSize().y/2));
    line1.rotate(45.f);
    line1.setPosition(sf::Vector2f(1000, 500));

    sf::RectangleShape line2(sf::Vector2f(150, 5));
    line2.setOrigin(sf::Vector2f(line2.getSize().x/2, line2.getSize().y/2));
    line2.rotate(135);
    line2.setPosition(sf::Vector2f(1000, 500));

    sf::RectangleShape linetab[2];

    sf::Vector2f posCircle;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // on lit la position locale de la souris (relativement à une fenêtre)
            localPosition = sf::Mouse::getPosition(window); // window est un sf::Window
            posCircle = sf::Vector2f((float)localPosition.x, (float)localPosition.y);
            board.setCircle(posCircle);
            // line1.setPosition((float)localPosition.x, (float)localPosition.y);
            // line2.setPosition((float)localPosition.x, (float)localPosition.y);
        }

        window.clear();
        window.draw(board.getContourPlateau());
        for(int i = 0; i < board.getNbLigne(); i++)
        {
            window.draw(board.getLignePlateau(i));
        }
        if(board.getNbCircle() != 0) window.draw(board.getCircle(0));
        // if(line1.getPosition() != forigin) window.draw(line1);
        // if(line2.getPosition() != forigin) window.draw(line2);
        // window.draw(line1);
        // window.draw(line2);
        
        
        window.display();
    }

    window.close();
    return 0;
}
