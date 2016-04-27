#include"spiderspawner.h"
#include "shoe.h"


spiderspawner::spiderspawner()
{
	pHead = nullptr;
	size = 0;
	mspiderRemaining = 0;
}
spiderspawner::~spiderspawner()
 {
	this->purge();
	}

void spiderspawner::spawnspiders(int howmany)
{
	int i = 0;

	for (i = 0; i < howmany; i++)
	{
		this->push(size);
		size++;
		 ++mspiderRemaining;
	}
}

void spiderspawner::movespiders()
{
	spider *pWalk = pHead;
	int i;
	for (i = 0; i < mspiderRemaining; i++)
	{
		if (pWalk->getPosition().y < 650)
			pWalk->setposition(float(pWalk->getPosition().x), float(pWalk->getPosition().y) + 0.1);
		else if (pWalk->getPosition().y >= 650 && pWalk->getPosition().x < 360)
			pWalk->setposition(float(pWalk->getPosition().x) + 0.1, float(pWalk->getPosition().y));
		else if (pWalk->getPosition().y >= 650 && pWalk->getPosition().x > 480)
			pWalk->setposition(float(pWalk->getPosition().x) - 0.1, float(pWalk->getPosition().y));
		pWalk = pWalk->getnext();
	}
}
void spiderspawner::killspider(int i)
{
	this->pop(i);
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
		this->spawnspiders(challenge + 3);
		break;
	case 17000:
		this->spawnspiders(challenge);
		break;
	case 18000:
		this->spawnspiders(challenge + 3);
		break;
	case 19000:
		this->spawnspiders(challenge + 2);
		break;
	case 20000:
		this->spawnspiders(challenge + 3);
		break;
	case 21000:
		this->spawnspiders(challenge + 2);
		break;
	case 22000:
		this->spawnspiders(challenge);
		break;
	case 23000:
		this->spawnspiders(challenge + 4);
		break;
	default:
		break;
	}
}

void spiderspawner::push(int i)
{
	spider *pMem = new spider(i);
	int x;
	pMem->setposition(rand() % 800, -50);
	pMem->setnext(pHead);
	pHead->setprev(pMem);
	pHead = pMem;
}
void spiderspawner::pop(int i)
{
	spider *pWalk = pHead, *pTemp, *pAft;
	int j = 0;
	while ((pWalk != nullptr) && (pWalk->getid() != i))
	{
		pWalk = pWalk->getnext();
	}
	if (pWalk != nullptr) {
		if (pWalk == pHead)
		{
			pHead = pWalk->getnext();
		}
		else
		{
			pTemp = pWalk->getprev();
			if (pWalk->getnext() != nullptr)
			{
				pTemp->setnext(pWalk->getnext());
				pAft = pWalk->getnext();
				pAft->setprev(pWalk->getprev());
			}
			else
				pTemp->setnext(nullptr);
		}
		delete pWalk;
	}
	else {
		cout << "pWalk cannot find i , dummy" << std::endl;
	}
}
spider * spiderspawner::getpHead()
{
	return pHead;
}
void spiderspawner::setpHead(spider *newPointer)
{
	pHead = newPointer;
}

int spiderspawner::getSpiderRemaining()
{
	return mspiderRemaining;
}

void spiderspawner::setSpiderRemaining(int spiderRemaining)
{
	mspiderRemaining = spiderRemaining;
}

void spiderspawner::drawspiders(sf::RenderWindow &window)
{
	spider* pWalk = pHead;
	int i = 0;
	for (i = 0; i < (mspiderRemaining); i++)
	{
		pWalk->draw(window);
		pWalk = pWalk->getnext();
	}
}

void spiderspawner::purge()
{
	spider* pWalk = pHead, *pAft;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		pAft = pWalk;
		pWalk = pWalk->getnext();
		delete pWalk;
	}
}