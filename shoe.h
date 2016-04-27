#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Shoe : public sf::RectangleShape
{
public:
	Shoe()
	{
		if (shoeTexture.loadFromFile("sm_splat.png")) {
			shoeSprite.setTexture(shoeTexture);
			
		}
		else { std::cout << "Splat didn't load...\n"; }
		sf::Vector2f size (10, 10);
		setSize(size);

		sf::Vector2f position(5000, 5000);

		shoeSprite.setPosition(position);
	};

	~Shoe()
	{
	};

	void setSpritePosition(sf::Vector2f position);
	void drawSplat(sf::RenderWindow &window);


private:
	sf::Sprite shoeSprite;
	sf::Texture shoeTexture;


};


