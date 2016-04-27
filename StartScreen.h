#pragma once
#include "Background.h"

class StartScreen :public Background
{
public:
	StartScreen();
	StartScreen(sf::RenderWindow &window);
	~StartScreen();

	void drawStartScreen(sf::RenderWindow &window);
private:
	sf::Font font;
	sf::Text text;
	sf::Text startText;
};
//non-member function 
void initializeText(sf::Font &font, sf::Text &text, float x_position, float y_position, int size = 50);


StartScreen::StartScreen() :Background()
{
	if (font.loadFromFile("holojacketcond.ttf"))
	{
		initializeText(font, text, 300, 300, 70);
		initializeText(font, startText, 650, 500);
	}
	text.setString("Save Your \nBaby Brother!");
	startText.setString("Start");
}
StartScreen::StartScreen(sf::RenderWindow &window) :Background()
{
	if (font.loadFromFile("holojacketcond.ttf"))
	{
		initializeText(font, text, window.getPosition().x , window.getPosition().y - 50, 70);
		initializeText(font, startText, window.getPosition().x + 20.0, window.getPosition().y + 10.0);
	}
	text.setString("Save Your Baby Brother!");
	startText.setString("Start");
}
StartScreen::~StartScreen()
{

}
//draws a start Screen
void StartScreen::drawStartScreen(sf::RenderWindow &window)
{
	drawBackground(window);
	window.draw(this->text);
	window.draw(this->startText);
}
//function to initialize the text easier
//precondition: the Font must have opened correctly
void initializeText(sf::Font &font, sf::Text &text, float x_position, float y_position, int size)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setPosition(x_position, y_position);
	text.setColor(sf::Color::White);
}
