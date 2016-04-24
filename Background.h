#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

class Background
{
public:
	Background();	//set the wallpaper and cribe texture
	~Background();

	void setBabyBroPoisition(float x, float y);
	void drawBackground(sf::RenderWindow &window);

private:
	sf::Sprite wallpaper;
	sf::Sprite babybro;
	sf::Texture tWallpaper;
	sf::Texture tBabybro;
};

Background::Background()
{
	if ((!tWallpaper.loadFromFile("baby-Girl-room-wallpaper-12.jpg")) || (!tBabybro.loadFromFile("baby.png")))
		cout << "Wallpaper didn't load." << endl;
	else
	{
		wallpaper.setTexture(tWallpaper);
		babybro.setTexture(tBabybro);
	}
	float x = 0, y = 0;
	babybro.setPosition(285, 379);
}
Background::~Background()
{
	
}

void Background::setBabyBroPoisition(float x, float y)
{
	babybro.setPosition(x, y);
}

void Background::drawBackground(sf::RenderWindow &window)
{
	window.draw(wallpaper);
	window.draw(babybro);
}
