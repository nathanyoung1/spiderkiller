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

// ****** SPIDER CONSTANTS
int const spiderWidth = 100;			// spinder png size (note, I lowered the size of the target area to make it more challenging and "realistic"
int const spiderLength = 90;

int main() {

	sf::RenderWindow window(sf::VideoMode(960, 720), "Spider Killer!!!");

	srand((unsigned int)time(NULL));
	int i;
	sf::Clock clock;

	Shoe testShoe;
	spiderspawner test;
	Background backdrop;
	ScoreBar score;
	bool splat;
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
				testShoe.setPosition(sf::Mouse::getPosition(window).x - (shoeWidth / 2),
					sf::Mouse::getPosition(window).y - (shoeLength / 2));
				splat = collisionDetection(test, testShoe);
				testShoe.setPosition(-100, -100);

			}

			if (event.type == sf::Event::Closed)
				window.close();
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
		window.draw(testShoe);

		//if (clock.getElapsedTime() < time) {
		//	window.draw(shoe);
		//}


		window.display();
	}

}

