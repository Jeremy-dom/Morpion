#include "Plateau.h"


Plateau::Plateau(sf::Vector2u windowSizeu)
{
    float posX, posY;
    sf::Vector2f windowSizef = static_cast<sf::Vector2f>(windowSizeu);

    sf::Vector2f sizePlateau(windowSizef.y*0.7f, windowSizef.y*0.7f);
    m_contourPlateau.setSize(sizePlateau);
    posX = (windowSizef.x - windowSizef.y*0.7) / 2;
    posY = (windowSizef.y - windowSizef.y*0.7) / 2;
    sf::Vector2f posPlateau(posX, posY);
    m_contourPlateau.setPosition(posPlateau);

    m_contourPlateau.setFillColor(sf::Color(0, 0, 0));
    m_contourPlateau.setOutlineThickness(5.f);



    for(int i = 0; i < 4; i++)
    {
        int mod2i = i%2;
        int nbligne = i/2 + 1;
        sf::RectangleShape ligne;
        if(mod2i == 0) //Ligne Verticale
        {
            ligne.setSize(sf::Vector2f(5, sizePlateau.y));
            ligne.setPosition(posX + nbligne*sizePlateau.x/3, posY);
        }
        else //Ligne Horizontale
        {
            ligne.setSize(sf::Vector2f(sizePlateau.x, 5));
            ligne.setPosition(posX, posY + nbligne*sizePlateau.y/3);
        }
        m_lignePlateau.push_back(ligne);
    }

}

int Plateau::getNbLigne()
{
    return m_lignePlateau.size();
}

int Plateau::getNbCircle()
{
    return m_circle.size();
}

sf::RectangleShape Plateau::getContourPlateau()
{
    return m_contourPlateau;
}

sf::RectangleShape Plateau::getLignePlateau(int index)
{
    return m_lignePlateau[index];
}

sf::CircleShape Plateau::getCircle(int index)
{
    return m_circle[index];
}

int Plateau::setCircle(sf::Vector2f pos)
{
    sf::CircleShape circle(50.f);
    circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
    circle.setFillColor(sf::Color(0, 0, 0));
    circle.setOutlineThickness(5.f);
    circle.setPosition(pos);

    m_circle.push_back(circle);
    return 0;
}

