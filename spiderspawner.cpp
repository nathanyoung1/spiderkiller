#include"spiderspawner.h"



spiderspawner::spiderspawner()
{
	pHead = nullptr;
	pTail = nullptr;
	size = 0;
}
spiderspawner::~spiderspawner()
{}

void spiderspawner::spawnspiders(int howmany)
{
	int i = 0;

	for (i = 0; i < howmany; i++)
		push();
	size = size + howmany;
}

void spiderspawner::movespiders()
{
	spider *pWalk = pHead;
	int i;
	for (i = 0; i < size; i++)
	{
		if (pWalk->getPosition().y < 650)
			pWalk->setposition(float(pWalk->getPosition().x), float(pWalk->getPosition().y) + 0.1);
		else if (pWalk->getPosition().y >= 650 && pWalk->getPosition().x < 433)
			pWalk->setposition(float(pWalk->getPosition().x) + 0.1, float(pWalk->getPosition().y));
		else if (pWalk->getPosition().y >= 650 && pWalk->getPosition().x > 490)
			pWalk->setposition(float(pWalk->getPosition().x) - 0.1, float(pWalk->getPosition().y));
		pWalk = pWalk->getnext();
	}
}

void spiderspawner::killspider(int i)
{
	this->pop();
}

void spiderspawner::thechallenge(sf::Clock &timer, int round)
{
	int challenge;
	switch (round)
	{
	case 1:
		challenge = 0;
		break;
	case 2:
		challenge = 1;
		break;
	case 3:
		challenge = 3;
		break;
	default:
		break;
	}
	switch (timer.getElapsedTime().asMilliseconds())
	{
	case 1000:
		this->spawnspiders(challenge + 1);
		break;
	case 2000:
		this->spawnspiders(challenge);
		break;
	case 3000:
		this->spawnspiders(challenge + 1);
		break;
	case 4000:
		this->spawnspiders(challenge);
		break;
	case 5000:
		this->spawnspiders(challenge + 2);
		break;
	case 6000:
		this->spawnspiders(challenge);
		break;
	case 7000:
		this->spawnspiders(challenge + 2);
		break;
	case 8000:
		this->spawnspiders(challenge + 1);
		break;
	case 9000:
		this->spawnspiders(challenge);
		break;
	case 10000:
		this->spawnspiders(challenge + 2);
		break;
	case 11000:
		this->spawnspiders(challenge + 3);
		break;
	case 12000:
		this->spawnspiders(challenge);
		break;
	case 13000:
		this->spawnspiders(challenge + 3);
		break;
	case 14000:
		this->spawnspiders(challenge);
		break;
	case 15000:
		this->spawnspiders(challenge + 4);
		break;
	case 16000:
		this->spawnspiders(challenge + 5);
		break;
	case 17000:
		this->spawnspiders(challenge);
		break;
	case 18000:
		this->spawnspiders(challenge + 3);
		break;
	case 19000:
		this->spawnspiders(challenge + 3);
		break;
	case 20000:
		this->spawnspiders(challenge + 3);
		break;
	case 21000:
		this->spawnspiders(challenge + 3);
		break;
	case 22000:
		this->spawnspiders(challenge);
		break;
	case 23000:
		this->spawnspiders(challenge);
		break;
	case 24000:
		this->spawnspiders(challenge + 4);
		break;
	case 25000:
		this->spawnspiders(challenge + 3);
		break;
	case 26000:
		this->spawnspiders(challenge + 4);
		break;
	case 27000:
		this->spawnspiders(challenge + 3);
		break;
	case 28000:
		this->spawnspiders(challenge + 4);
		break;
	case 29000:
		this->spawnspiders(challenge + 3);
		break;
	default:
		break;
	}
}

void spiderspawner::push()
{
	spider *pMem = new spider();
	int x;
	//srand((unsigned int)time(NULL));
	pMem->setposition(rand() % 960, -50);
	pMem->setnext(pHead);
	pHead = pMem;
}
void spiderspawner::pop()
{
	spider *pMem = pTail;
	pTail = pMem->getprev();
	delete pMem;
}

void spiderspawner::drawspiders(sf::RenderWindow &window)
{
	spider* pWalk = pHead;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		pWalk->draw(window);
		pWalk = pWalk->getnext();
	}
}
