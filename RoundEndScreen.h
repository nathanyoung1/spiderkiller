#pragma once
#include <SFML/Graphics.hpp>

class RoundEndScreen
{
public:
	RoundEndScreen();
	~RoundEndScreen();

	void drawRoundEndScreen(sf::RenderWindow &window, int kills, int lives);
private:
	sf::Font font;
	sf::Text winLoseText;
	sf::Text KillsText;
	sf::Text LivesText;

	void initializeText(sf::Font &font, sf::Text &text, float x_position, float y_position, int size = 50);
};
