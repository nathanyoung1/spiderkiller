#include "ScoreBar.h"


ScoreBar::ScoreBar()
{
	font.loadFromFile("holojacketcond.ttf");
	lives = 3;
	hits = 0;

	timer.setFont(font);
	timer.setPosition(700, 5);
	timer.setCharacterSize(50);

	livesText.setFont(font);
	livesText.setPosition(50, 5);
	livesText.setCharacterSize(50);

	hitsText.setFont(font);
	hitsText.setPosition(200, 5);
	hitsText.setCharacterSize(50);
}
ScoreBar::~ScoreBar()
{

}

void ScoreBar::setHits(int newHits)
{
	this->hits = newHits;
}
void ScoreBar::setLives(int newLives)
{
	this->hits = newLives;
}

int ScoreBar::getHits()
{
	return hits;
}
int ScoreBar::getLives()
{
	return lives;
}

//Adds one to the kill count
void ScoreBar::addHit()
{
	hits = hits + 1;
}
//Subtracts one from the Life counter until life is equal to zero
void ScoreBar::takeLife()
{
	if (lives != 0)
	{
		lives--;
	}
}

sf::Vector2f ScoreBar::getTimerPosition()
{
	return timer.getPosition();
}
void ScoreBar::setTimerPosition(float x, float y)
{
	timer.setPosition(x, y);
}
// Just draws only the lives counter
void ScoreBar::drawLives(sf::RenderWindow &window)
{
	string str;

	//update string in case the number of lives has changed
	str = "Lives: " + std::to_string(lives);
	livesText.setString(str);

	window.draw(livesText);
}
// Just draws only the hits counter 
void ScoreBar::drawHits(sf::RenderWindow &window)
{
	string str;

	//update string in case the number of hits has changed 
	str = "Hits: " + std::to_string(hits);
	hitsText.setString(str);

	window.draw(hitsText);
}
// Draws just the timer 
void ScoreBar::drawtimer(sf::RenderWindow &window, sf::Clock &clock)
{
	string str;

	str = "Clock: " + std::to_string(30 - int(clock.getElapsedTime().asSeconds()));
	timer.setString(str);

	window.draw(timer);
}
// Draws the timer, number of hits, and number of lives left - don't need to draw each separately this way
void ScoreBar::drawScoreBar(sf::RenderWindow &window, sf::Clock &clock)
{
	drawHits(window);
	drawLives(window);
	drawtimer(window, clock);
}