#include <SFML/Graphics.hpp>
#include"spiderstructure.h"
#include"spiderspawner.h"
#include"Background.h"
#include"ScoreBar.h"
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
	}

}
