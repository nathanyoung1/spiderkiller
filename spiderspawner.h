#pragma once
#include <SFML/Graphics.hpp>
#include "spiderstructure.h"
#include <time.h>



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

	void push(int i);
	void pop(int i);
private:
	spider *pHead;
	int size;
};
