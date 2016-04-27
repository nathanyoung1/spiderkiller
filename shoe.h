#pragma once
#include <SFML/Graphics.hpp>

class Shoe : public sf::RectangleShape
{
public:
	Shoe()
	{
		if (shoeTexture.loadFromFile("sm_shoe.png")) {
			shoeSprite.setTexture(shoeTexture);
			
		}
		sf::Vector2f size (10, 10);
		setSize(size);

		sf::Vector2f position(500, 500);

		setPosition(position);
	};

	~Shoe()
	{
	};



private:
	sf::Sprite shoeSprite;
	sf::Texture shoeTexture;


};
