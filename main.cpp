#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include<time.h>


#include "physics.h"
#include "spiderstructure.h"
#include "spiderspawner.h"
#include "Background.h"
#include "ScoreBar.h"
#include "shoe.h"

using std::cout;
using std::endl;


// ****** SHOE CONSTANTS
int const shoeWidth = 10;				// shoe size
int const shoeLength = 10;

int main() {

	sf::RenderWindow window(sf::VideoMode(960, 720), "Spider Killer!!!");

	srand((unsigned int)time(NULL));
	int i;
	sf::Clock clock;
	sf::Clock splatTimer;

	Shoe testShoe;
	spiderspawner test;
	Background backdrop;
	ScoreBar score;
	bool splat;
	bool splat1 = false;
	int kills = 0;

	// velocity of shoe (in x and y direction)
	double velocity_x = 0;
	double velocity_y = 0;
	float flightTime = 0;		// we'll calculate flight time based on position and x velocity (which we'll calculate)
	sf::Vector2f velocity(sf::Vector2f(0, 0));

	// SETTING CLOCK
	sf::Time time = sf::seconds(2.0);
	sf::Time delay = sf::seconds(2.0);

	while (window.isOpen()) {
		splat = false;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {
				// when button pressed, sets shoe's position.  this is OFFSET by 1/2 shoe length and width BECAUSE the center of the shoe should be positioned to where you clicked on screen
				testShoe.setPosition((float)(sf::Mouse::getPosition(window).x - (shoeWidth / 2)),
					(float)(sf::Mouse::getPosition(window).y - (shoeLength / 2)));
				splat = collisionDetection(test, testShoe);	// returns TRUE of collision of shoe with spider occurs.
				splat1 = splat;								// splat 1 is used to test if we display splat (see below)
				splatTimer.restart();
			}

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		test.movespiders();

		test.thechallenge(clock, 1);

		// collision detection
		// looks through the spiderspawn linked list and detect collision
		// if shoe steps on spider, we delete the node in linked list, and diplay a "splat"

		window.clear();


		backdrop.drawBackground(window);
		score.drawScoreBar(window, clock);
		test.drawspiders(window);
		
		// this is reposnisble for displaying the splat.  splat stays up for 2 seconds OR until it gets clicked again
		if (splat1 == true) {
			if (splatTimer.getElapsedTime().asSeconds() < 2) {
				testShoe.setSpritePosition(testShoe.getPosition());
				testShoe.drawSplat(window);
			}
			else
			{
					splat1 = false;
			}
		}
		window.display();

	}

}

