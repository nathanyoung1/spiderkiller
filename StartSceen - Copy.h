#pragma once
#include "Background.h"

class StartScreen :public Background
{
public:
	StartScreen();
	StartScreen(sf::RenderWindow &window);
	~StartScreen();

	void drawStartScreen(sf::RenderWindow &window, int level);
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
		initializeText(font, text, 10, 10, 70);
		initializeText(font, startText, 10, 70);
	}
	startText.setString("Click to Start");
}
StartScreen::StartScreen(sf::RenderWindow &window) :Background()
{
	if (font.loadFromFile("holojacketcond.ttf"))
	{
		initializeText(font, text, window.getPosition().x, window.getPosition().y - 50, 70);
		initializeText(font, startText, window.getPosition().x + 20.0, window.getPosition().y + 10.0);
	}
	startText.setString("Click to Start");
}
StartScreen::~StartScreen()
{

}
//draws a start Screen
void StartScreen::drawStartScreen(sf::RenderWindow &window, int level)
{
	drawBackground(window);
	if (level < 4) {
		text.setString("Level " + std::to_string(level));
		window.draw(this->startText);
	}
	else {
		text.setString("You Won All Levels!");
	}
	window.draw(this->text);
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