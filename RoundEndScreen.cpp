#pragma once
#include "RoundEndScreen.h"

using std::string;

RoundEndScreen::RoundEndScreen()
{
	if (font.loadFromFile("holojacketcond.ttf"))
	{
		winLoseText.setFont(font);
		KillsText.setFont(font);
		LivesText.setFont(font);

		winLoseText.setCharacterSize(70);
		KillsText.setCharacterSize(50);
		LivesText.setCharacterSize(50);

		winLoseText.setPosition(200, 100);
		KillsText.setPosition(400, 350);
		LivesText.setPosition(400, 400);

		winLoseText.setColor(sf::Color::White);
		KillsText.setColor(sf::Color::White);
		LivesText.setColor(sf::Color::White);
	}
}
RoundEndScreen::~RoundEndScreen()
{

}
// draws the win loss status, the number of kills, and the number of lives
void RoundEndScreen::drawRoundEndScreen(sf::RenderWindow &window, int kills, int lives)
{
	//set the strings 
	string str = "";

	//set the win lose text 
	if (lives != 0)
		str = "You Saved Baby Brother!";
	else
		str = "Call The Baby Hospital!";
	winLoseText.setString(str);

	//set the killsText
	str = "Kills:  " + std::to_string(kills);
	KillsText.setString(str);

	//set the LivesText
	str = "Lives:  " + std::to_string(lives);
	LivesText.setString(str);

	window.draw(winLoseText);
	window.draw(KillsText);
	window.draw(LivesText);
}
//private function to initialize the text easier
//precondition: the Font must have opened correctly
void RoundEndScreen::initializeText(sf::Font &font, sf::Text &text, float x_position, float y_position, int size)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setPosition(x_position, y_position);
	text.setColor(sf::Color::White);
}
