#include"spiderspawner.h"



spiderspawner::spiderspawner()
{
	int i;
	for (i = 0; i < 10; i++)
		charlotte[i].setposition(-50, -50);
}
spiderspawner::~spiderspawner()
{}

void spiderspawner::spawnspiders(int howmany)
{
	srand((unsigned int)time(NULL));
	bool start;
	int i = 0;
	while (charlotte[i].iskilled() == true)
		i++;
	int j = i;
	for (j = i; j < (i + howmany); j++)
	{
		charlotte[j].setposition(rand() % 960, -50);
		charlotte[j].activate();
	}
}

void spiderspawner::movespiders()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if(charlotte[i].isactive() == true && charlotte[i].getPosition().y < 650)
			charlotte[i].setposition(float(charlotte[i].getPosition().x), float(charlotte[i].getPosition().y) + 2);
		else if(charlotte[i].isactive() == true && charlotte[i].getPosition().y >= 650 && charlotte[i].getPosition().x < 433)
			charlotte[i].setposition(float(charlotte[i].getPosition().x) + 2, float(charlotte[i].getPosition().y));
		else if (charlotte[i].isactive() == true && charlotte[i].getPosition().y >= 650 && charlotte[i].getPosition().x > 490)
			charlotte[i].setposition(float(charlotte[i].getPosition().x) - 2, float(charlotte[i].getPosition().y));
	}
}

spider spiderspawner::getspider(int i)
{
	return charlotte[i];
}

void spiderspawner::killspider(int i)
{
	charlotte[i].kill();
}