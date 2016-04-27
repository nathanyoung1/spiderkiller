#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class ScoreBar
{
public:
	ScoreBar();
	~ScoreBar();

	void setHits(int newHits);
	void setLives(int newLives);

	int getHits();
	int getLives();

	void addHit();
	void takeLife();

	sf::Vector2f getTimerPosition();
	void setTimerPosition(float x, float y);

	void drawLives(sf::RenderWindow &window);
	void drawHits(sf::RenderWindow &window);
	void drawtimer(sf::RenderWindow &window, sf::Clock &clock);
	void drawScoreBar(sf::RenderWindow &window, sf::Clock &clock);

private:
	int lives;
	int hits;
	sf::Font font;
	sf::Text timer;
	sf::Text livesText;
	sf::Text hitsText;
};