#pragma once
#include <SFML/Graphics.hpp>
#include "spiderstructure.h"
#include<time.h>



class spiderspawner
{
public:
	spiderspawner();
	~spiderspawner();

	void spawnspiders(int howmany);
	void movespiders();

	spider getspider(int i);
	
	void killspider(int i);
private:
	spider charlotte[10];
};