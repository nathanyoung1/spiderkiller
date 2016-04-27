#pragma once
#include "spiderspawner.h"
#include "shoe.h"
bool collision(sf::Vector2i tempSpritePosition, sf::Vector2i tempSpriteWH,
	sf::Vector2i tempCollisionBoxPosition, sf::Vector2i tempCollisionBoxWH);

bool collisionDetection(spiderspawner &test, Shoe &shoe);