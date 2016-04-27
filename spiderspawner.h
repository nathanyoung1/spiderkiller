#pragma once
#include <SFML/Graphics.hpp>
#include "spiderstructure.h"
#include<time.h>

//if (player.getGlobalBounds().intersects(p1.getGlobalBounds())) clock.restart();


class spiderspawner
{
public:
	spiderspawner();
	~spiderspawner();

	void spawnspiders(int howmany);
	void movespiders();
	void drawspiders(sf::RenderWindow &window);
	void killspider(int i);
	void purge();

	void thechallenge(sf::Clock &timer, int round);
	spider*getpHead();
	void setpHead(spider *newPointer);
	int getSpiderRemaining();

	void setSpiderRemaining(int spiderRemaining);

	void push(int i);
	void pop(int i);
private:
	spider *pHead;
	int size;
	int mspiderRemaining;
};


