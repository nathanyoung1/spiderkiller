#pragma once

#include <SFML/Graphics.hpp>
using std::cout;


class spider
{
public:
	
	spider();
	~spider();
	
	void move(float offsetX, float offsetY);
	void setposition(float positionX, float positiony);
	sf::Vector2f getPosition();
	spider* getnext();
	void setnext(spider *next);
	spider* getprev();
	void draw(sf::RenderWindow &window);
private:
	sf::Sprite it;
	sf::Texture tit;
	spider *pNext;
	spider *pLast;
};
