#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
using std::cout;


class spider
{
public:
	
	spider(int nid);
	~spider();
	
	void move(float offsetX, float offsetY);
	void setposition(float positionX, float positiony);
	sf::Vector2f getPosition();
	spider* getnext();
	void setnext(spider *next);
	spider* getprev();
	void setprev(spider *prev);
	void draw(sf::RenderWindow &window);
	int getid();
private:
	sf::Sprite it;
	sf::Texture tit;
	spider *pNext;
	spider *pLast;
	int id;
};
