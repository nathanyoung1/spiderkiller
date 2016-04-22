#pragma once

#include <SFML/Graphics.hpp>


class spider : public sf::RectangleShape
{
public:
	spider(float positionx = 0, float positiony = 0);
	~spider();
	sf::RectangleShape getleg(int which);
	sf::CircleShape getbody();
	void move(float offsetX, float offsetY);

private:
	sf::RectangleShape leg[16];
	sf::CircleShape body;
	float positionx;
	float positiony;
};