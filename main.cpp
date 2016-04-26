#include <SFML/Graphics.hpp>
#include"spiderstructure.h"
#include"spiderspawner.h"
#include"Background.h"
#include"ScoreBar.h"
#include "RoundEndScreen.h"
#include<time.h>

using std::cout;
using std::endl;

int main() {

	sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Application");

	srand((unsigned int)time(NULL));
	int i;
	sf::Clock clock;

	spiderspawner test;
	Background backdrop;
	ScoreBar score;
	RoundEndScreen roundEnd;


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
				cout << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << endl;
		}

		test.movespiders();
		
		test.thechallenge(clock, 1);

		window.clear();

		backdrop.drawBackground(window);
		score.drawScoreBar(window, clock);
		test.drawspiders(window);
		window.display();
		
		//MICHELLE (This is what I changed for the end of round screen)
		window.clear();
		//check for the end of the round
		if (clock.getElapsedTime().asMilliseconds() >= 30500 || score.getLives() == 0)
		{
			//end of the round
			roundEnd.drawRoundEndScreen(window, score.getHits(), score.getLives());
		}
		else
		{
			test.movespiders();
		
			test.thechallenge(clock, 1);

			backdrop.drawBackground(window);
			score.drawScoreBar(window, clock);
			test.drawspiders(window);
			window.display();
		}
		window.display();
		//END OF MICHELLE
	}

}
