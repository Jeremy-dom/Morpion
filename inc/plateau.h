#ifndef __PLATEAU_H__
#define __PLATEAU_H__

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Plateau
{
    public :
    
        Plateau(sf::Vector2u windowSizeu);

        int getNbLigne();
        int getNbCircle();
        int getNbCross();

        sf::RectangleShape getContourPlateau();
        sf::RectangleShape getLignePlateau(int index);
        sf::CircleShape getCircle(int index);
        sf::RectangleShape getCrossLine1(int index);
        sf::RectangleShape getCrossLine2(int index);

        int setSymbol(sf::Vector2f pos, int joueur);
        sf::RectangleShape setRestartButton();
        sf::Text setRestartText(sf::Font font);



        int checkWinner();
        int clickReset(sf::Vector2f pos);
        int resetGame();


    private :

        sf::RectangleShape m_contourPlateau;
        std::vector<sf::RectangleShape> m_lignePlateau;
        std::vector<sf::CircleShape> m_circle;
        std::vector<sf::RectangleShape> m_crossLine1;
        std::vector<sf::RectangleShape> m_crossLine2;
        sf::RectangleShape restartButton;

        sf::Vector2f assignPos(sf::Vector2f initialPos, int symbol);
        int setCircle(sf::Vector2f pos);
        int setCross(sf::Vector2f pos);

        int symbolPlateau[3][3] = {{},{}};
};


#endif //__PLATEAU_H__