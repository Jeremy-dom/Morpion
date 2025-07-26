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

    m_contourPlateau.setFillColor(sf::Color::Black);
    m_contourPlateau.setOutlineThickness(5.f);



    for(int i = 0; i < 4; i++)
    {
        int mod2i = i%2;
        int nbligne = i/2 + 1;
        sf::RectangleShape ligne;
        if(mod2i == 0) //Ligne Verticale
        {
            ligne.setSize(sf::Vector2f(5, sizePlateau.y));
            ligne.setPosition({posX + nbligne*sizePlateau.x/3, posY});
        }
        else //Ligne Horizontale
        {
            ligne.setSize(sf::Vector2f(sizePlateau.x, 5));
            ligne.setPosition({posX, posY + nbligne*sizePlateau.y/3});
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

int Plateau::getNbCross()
{
    return m_crossLine1.size();
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

sf::RectangleShape Plateau::getCrossLine1(int index)
{
    return m_crossLine1[index];
}

sf::RectangleShape Plateau::getCrossLine2(int index)
{
    return m_crossLine2[index];
}

int Plateau::setCircle(sf::Vector2f pos)
{
    sf::Vector2f newPos = assignPos(pos);
    if(newPos.x == -1 || newPos.y == -1)
        return -1;
    else
    {
        sf::CircleShape circle(50.f);
        circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
        circle.setFillColor(sf::Color::Black);
        circle.setOutlineThickness(5.f);
        circle.setPosition(newPos);

        m_circle.push_back(circle);
    }
    return 0;
}

int Plateau::setCross(sf::Vector2f pos)
{
    sf::Vector2f newPos = assignPos(pos);
    if(newPos.x == -1 || newPos.y == -1)
        return -1;
    else
    {
        sf::RectangleShape line1(sf::Vector2f(150, 5));
        line1.setOrigin(sf::Vector2f(line1.getSize().x/2, line1.getSize().y/2));
        line1.rotate(sf::degrees(45));
        line1.setPosition(newPos);

        sf::RectangleShape line2(sf::Vector2f(150, 5));
        line2.setOrigin(sf::Vector2f(line2.getSize().x/2, line2.getSize().y/2));
        line2.rotate(sf::degrees(135));
        line2.setPosition(newPos);

        m_crossLine1.push_back(line1);
        m_crossLine2.push_back(line2);
        return 0;
    }
}

sf::Vector2f Plateau::assignPos(sf::Vector2f initialPos)
{
    int cPosX, cPosY;
    int cSizeX = getLignePlateau(2).getPosition().x - getLignePlateau(0).getPosition().x;
    int cSizeY = getLignePlateau(3).getPosition().y - getLignePlateau(1).getPosition().y;

    std::cout << "Taille d'une case : " << cSizeX << " - " << cSizeY << std::endl;

    int c1PosX = getLignePlateau(0).getPosition().x - (getLignePlateau(2).getPosition().x - getLignePlateau(0).getPosition().x)/2;
    int c1PosY = getLignePlateau(1).getPosition().y - (getLignePlateau(3).getPosition().y - getLignePlateau(1).getPosition().y)/2;

    std::cout << "Position de la première case : " << c1PosX << " - " << c1PosY << std::endl;

    sf::Vector2f newPos = initialPos;

    if(initialPos.x < getLignePlateau(0).getPosition().x - cSizeX)
        cPosX = -1;
    else if(initialPos.x < getLignePlateau(0).getPosition().x)
        cPosX = 0;
    else if(initialPos.x < getLignePlateau(2).getPosition().x)
        cPosX = 1;
    else if(initialPos.x < getLignePlateau(2).getPosition().x + cSizeX)
        cPosX = 2;
    else
        cPosX = -1;

    if(initialPos.y < getLignePlateau(1).getPosition().y - cSizeY)
        cPosY = -1;
    else if(initialPos.y < getLignePlateau(1).getPosition().y)
        cPosY = 0;
    else if(initialPos.y < getLignePlateau(3).getPosition().y)
        cPosY = 1;
    else if(initialPos.y < getLignePlateau(3).getPosition().y + cSizeY)
        cPosY = 2;
    else
        cPosY = -1;

    std::cout << "Position assigné : " << cPosX << " - " << cPosY << std::endl;

    if(cPosX == -1 || cPosY == -1)
    {
        newPos.x = -1;
        newPos.y = -1;
    }
    else
    {
        newPos.x = c1PosX + cPosX * cSizeX;
        newPos.y = c1PosY + cPosY * cSizeY;
    }

    std::cout << "Position de la case : " << newPos.x << " - " << newPos.y << std::endl;

    return newPos;
}

