#include <SFML/Graphics.hpp>
#include"spiderstructure.h"
#include"spiderspawner.h"
#include"StartSceen.h"
#include"ScoreBar.h"
#include"shoe.h"
#include"physics.h"
#include"RoundEndScreen.h"
#include<time.h>

using std::cout;
using std::endl;

int main() {

	sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Application");

	srand((unsigned int)time(NULL));
	sf::Clock clock;
	sf::Clock splatTimer;

	spiderspawner test;
	Background backdrop;
	StartScreen sScreen;
	RoundEndScreen endScreen;
	ScoreBar score;
	Shoe stomp;


	int splat = 0;
	bool splat1 = false;
	bool start = false, end = false;	//to determine if we have started the game
	int level = 1;

	while (window.isOpen()) {
		cout << "End: " << end << "Start: " << start << endl;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				cout << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << endl;
				stomp.setPosition(sf::Mouse::getPosition(window).x - 10, sf::Mouse::getPosition(window).y - 10);
				if (test.getpHead() != nullptr)
					splat = collisionDetection(test, stomp);
				if (splat >= 1)
				{
					splat1 = true;								// splat 1 is used to test if we display splat (see below)
				}
				else
					splat1 = false;
				splatTimer.restart();
				score.addHit(splat);
			}
			if (start == false && end == false && level < 4 && event.type == sf::Event::MouseButtonPressed)
			{
				start = true;
				clock.restart(); //so game timer is correct
				score.setLives(3);
				score.setHits(0);
			}
			if (end == true && event.key.code == sf::Keyboard::Space)
			{
				end = false;
				if (score.getLives() != 0)
					level++;
				//clock.restart();
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//Show StartScreen or the game screen?
		if (start == false && end == false)
		{
			sScreen.drawStartScreen(window, level);
		}
		else
		{
			//Check for the end of the round
			if (clock.getElapsedTime().asMilliseconds() >= 31000 || score.getLives() <= 0)
			{
				end = true;
				//end of round 
				endScreen.drawRoundEndScreen(window, score.getHits(), score.getLives());
				test.purge();
				start = false;
			}
			else
			{
				score.setLives(score.getLives() - test.movespiders());

				test.thechallenge(clock, level);

				backdrop.drawBackground(window);
				score.drawScoreBar(window, clock);
				test.drawspiders(window);
				if (splat1 == true) {
					if (splatTimer.getElapsedTime().asSeconds() < 2) {
						stomp.setSpritePosition(stomp.getPosition());
						stomp.drawSplat(window);
					}
					else
						splat1 = false;
				}
				splat = 0;
			}
		}
		window.display();
	}

}
