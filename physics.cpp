
// FROM http://pastebin.com/Vwy8cm2k

/*Variable Explanations:
tempSpritePosition = Left and Top side of the Sprite
tempSpriteWH = The Width and Height of the Sprite
tempCollisionBoxPosition = Left and Top side of the Collision Box
tempCollisionBoxWH = The Width and Height of the Collision Box
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "physics.h"

using std::cout;
using std::endl;
using std::cin;

//Pass in top left cord of sprite + collisionbox, and both of their heights and widths
bool collision(sf::Vector2i tempSpritePosition, sf::Vector2i tempSpriteWH,
	sf::Vector2i tempCollisionBoxPosition, sf::Vector2i tempCollisionBoxWH)

{
	if (tempSpritePosition.x + tempSpriteWH.x > tempCollisionBoxPosition.x && tempSpritePosition.x < tempCollisionBoxPosition.x + tempCollisionBoxWH.x)
	{
		if (tempSpritePosition.y + tempSpriteWH.y > tempCollisionBoxPosition.y && tempSpritePosition.y < tempCollisionBoxPosition.y + tempCollisionBoxWH.y)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}


bool collisionDetection(spiderspawner &test, Shoe  &shoe)
{
	spider* pCur = nullptr;
	//spider* pPrev = nullptr;
	spider* pTemp = nullptr;
	int kills = 0;
	//int spiderID = 0;
	pCur = test.getpHead();

	while (pCur != nullptr)
	{
		//pTemp = pCur;


		// check collission is true with pTemp!
		if (shoe.getGlobalBounds().intersects(pCur->getGlobalBounds())) {
			pTemp = pCur;
			pCur = pCur->getnext();
			++kills;
			test.setSpiderRemaining(test.getSpiderRemaining() - 1);
			
			test.killspider(pTemp->getid());
		}
		

		// return true if a kill occurs.  return false if no kills occur
		if (kills > 0) {

			cout << "KILL"<<endl;
			return true;

		}
		else
			cout << "FAIL to KILL" <<endl;
			return false;

	
	}
}