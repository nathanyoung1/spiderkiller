#include <SFML/Graphics.hpp>
#include <iostream>
#include "physics.h"

using std::cout;
using std::endl;
using std::cin;



bool collisionDetection(spiderspawner &test, Shoe  &shoe)
{
	spider* pCur = nullptr;
	//spider* pPrev = nullptr;
	spider* pTemp = nullptr;
	int kills = 0;
	pCur = test.getpHead();

	sf::Vector2f shoePos((float)shoe.getPosition().x, (float)shoe.getPosition().y);
	sf::Vector2f spiderPos((float)test.getpHead()->getPosition().x, (float)test.getpHead()->getPosition().y);

	while (pCur != nullptr)
	{
		// check collission is true with pTemp!
		if (shoe.getGlobalBounds().intersects(pCur->getGlobalBounds())) {
			pTemp = pCur;
			pCur = pCur->getnext();
			++kills;
			test.setSpiderRemaining(test.getSpiderRemaining() - 1);

			test.killspider(pTemp->getid());
		}
		else {
			pCur = pCur->getnext();
		}
	}
	// return true if a kill occurs.  return false if no kills occur
	if (kills > 0) {

		cout << "KILL" << endl;
		return true;

	}
	else
		cout << "FAIL to KILL" << endl;
	return false;
}
