#include"shoe.h"

// obviosuly, draws the splat
void Shoe::drawSplat(sf::RenderWindow &window)
{
	window.draw(shoeSprite);
}

// sets the position of the sprite.  I magic numbered the vector position for convienience (and we're out of time)
void Shoe::setSpritePosition(sf::Vector2f position)
{
	position.x = position.x - 20;
	position.y = position.y - 20;
	shoeSprite.setPosition(position);

}
