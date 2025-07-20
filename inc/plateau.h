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

        sf::RectangleShape getContourPlateau();
        sf::RectangleShape getLignePlateau(int index);
        sf::CircleShape getCircle(int index);

        int setCircle(sf::Vector2f pos);


    private :

        sf::RectangleShape m_contourPlateau;
        std::vector<sf::RectangleShape> m_lignePlateau;
        std::vector<sf::CircleShape> m_circle;
        std::vector<sf::RectangleShape> m_crossLine1;
        std::vector<sf::RectangleShape> m_crossLine2;
};


#endif //__PLATEAU_H__