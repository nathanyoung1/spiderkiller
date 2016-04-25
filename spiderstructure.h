#pragma once

#include <SFML/Graphics.hpp>


class spider : public sf::RectangleShape
{
public:
	//spider(float positionx, float positiony);
	spider();
	~spider();
	sf::RectangleShape getleg(int which);
	sf::CircleShape getbody();
	void move(float offsetX, float offsetY);
	void setposition(float positionX, float positiony);
	sf::Vector2i getPosition();
	bool iskilled();
	bool isactive();
	void kill();
	void activate();
private:
	sf::RectangleShape leg[16];
	sf::CircleShape body;
	sf::Vector2i position;
	bool killed;
	bool active;
};
