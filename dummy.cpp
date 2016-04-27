///*******************************************************************************************
//* Group members:																		   *
//* Class: CptS 122, Fall  2016;								                               *
//* Programming Assignment: Final assingment      					                       *
//* Description: Clone of Doodle Jump														   *
//*******************************************************************************************/
//
////include local libraries
//#include "mainGame.h"
//
////constructor
//MainGame::MainGame()
//{
//	//hard values 
//	this->start = 0;
//	this->windowHeight = 480;
//	this->windowWidth = 240;
//	this->windowTitle = "Bee Jump";
//
//	//get textures
//	this->backgroundTexture.loadFromFile("background.jpg", sf::IntRect());
//	this->playerTexture.loadFromFile("player.png", sf::IntRect());
//	this->rampTexture.loadFromFile("ramp.png", sf::IntRect());
//}
//
////run main game
//void MainGame::runGame(void)
//{
//	//set up rand
//	srand(time(NULL)); //handle this evenetually
//
//					   //easier to amke window with teh construcotr
//	sf::RenderWindow window(sf::VideoMode(this->windowWidth, this->windowHeight), windowTitle,
//		sf::Style::Titlebar | sf::Style::Close);
//
//	this->background.setTexture(backgroundTexture);
//
//	// Character declarations
//	sf::RectangleShape player(sf::Vector2f(50, 50));
//	// Character Initial position
//	player.setPosition(window.getSize().x / 2, window.getSize().y - 20);
//	player.setTexture(&this->playerTexture);
//	float newX = 0;
//
//	// Time variables
//	sf::Clock clock;
//	sf::Time t;
//
//	// Score Variable
//	float speed = 0, score = 0;
//
//	// Platform variables
//	sf::Keyboard controls;
//	sf::RectangleShape p1(sf::Vector2f(40, 8));
//	sf::RectangleShape p2(sf::Vector2f(40, 8));
//	sf::RectangleShape p3(sf::Vector2f(40, 8));
//	sf::RectangleShape p4(sf::Vector2f(40, 8));
//	sf::RectangleShape p5(sf::Vector2f(40, 8));
//	/*p1.setFillColor(sf::Color::White);
//	p2.setFillColor(sf::Color::White);
//	p3.setFillColor(sf::Color::White);
//	p4.setFillColor(sf::Color::White);
//	p5.setFillColor(sf::Color::White);*/
//	p1.setPosition(rand() % 201, window.getSize().y * 1 / 5);
//	p2.setPosition(rand() % 201, window.getSize().y * 2 / 5);
//	p3.setPosition(rand() % 201, window.getSize().y * 3 / 5);
//	p4.setPosition(rand() % 201, window.getSize().y * 4 / 5);
//	p5.setPosition(rand() % 201, window.getSize().y);
//	p1.setTexture(&this->rampTexture);
//	p2.setTexture(&this->rampTexture);
//	p3.setTexture(&this->rampTexture);
//	p4.setTexture(&this->rampTexture);
//	p5.setTexture(&this->rampTexture);
//
//	// While the play window is open gameplay continues
//	int start = 0;
//	while (window.isOpen())
//	{
//		// Debug callouts
//		//cout << t.asSeconds() << "  Y: " << player.getPosition().y << "  X: " << player.getPosition().x << " Speed: " << speed << " Score: " << score << endl;
//
//
//		// Set time
//		t = clock.getElapsedTime();
//		// Set player/platform speed, this gives us a LOT more readability in code negative is up positive is down (visually)
//		speed = (4.9 * pow(t.asSeconds(), 2) - 5 * t.asSeconds());
//
//		if (!start)
//		{
//			speed = -10;
//			start = 1;
//		}
//
//
//		// Check if the player lost, ideally this would take them to a menu that can let them start again
//		if (player.getPosition().y > window.getSize().y) window.close();
//
//		// TEMPORARY
//		// If the player hits the bottom of the screen they bounce, eventually should be hitting platforms
//
//		// If and else statement that handle all upward movement
//		// If the player has reached the window max that they can get and are travelling upwards move platforms down
//		if ((player.getPosition().y <= window.getSize().y / 2) && (speed < 0)) {
//			p1.move(0, -speed);
//			p2.move(0, -speed);
//			p3.move(0, -speed);
//			p4.move(0, -speed);
//			p5.move(0, -speed);
//			score -= speed;
//		}
//		// Otherwise the player is moving in their playspace and if they are going down checking for intersections
//		else {
//			player.move(0, speed);
//			if (speed > 0) {
//				if (player.getGlobalBounds().intersects(p1.getGlobalBounds())) clock.restart();
//				if (player.getGlobalBounds().intersects(p2.getGlobalBounds())) clock.restart();
//				if (player.getGlobalBounds().intersects(p3.getGlobalBounds())) clock.restart();
//				if (player.getGlobalBounds().intersects(p4.getGlobalBounds())) clock.restart();
//				if (player.getGlobalBounds().intersects(p5.getGlobalBounds())) clock.restart();
//			}
//		}
//		if (p1.getPosition().y > window.getSize().y) p1.setPosition(rand() % 201, -10);
//		if (p2.getPosition().y > window.getSize().y) p2.setPosition(rand() % 201, -10);
//		if (p3.getPosition().y > window.getSize().y) p3.setPosition(rand() % 201, -10);
//		if (p4.getPosition().y > window.getSize().y) p4.setPosition(rand() % 201, -10);
//		if (p5.getPosition().y > window.getSize().y) p5.setPosition(rand() % 201, -10);
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			// Close window
//			if (event.type == sf::Event::Closed) window.close();
//			if (controls.isKeyPressed(sf::Keyboard::Escape)) window.close();
//
//			// Checks if left or right key is pressed and returns the players velocity
//			if (controls.isKeyPressed(sf::Keyboard::Left)) newX = -1.1;
//			else if (controls.isKeyPressed(sf::Keyboard::Right)) newX = 1.1;
//			else newX = 0;
//
//			// Checks the location of the button press
//			if (event.type == sf::Event::MouseButtonPressed) {
//				if (event.mouseButton.button == sf::Mouse::Left) {
//					cout << "mouse x: " << event.mouseButton.x << endl;
//				}
//			}
//		}
//		// If the player went out of one of the sides put them on the other side
//		if ((player.getPosition().x >= window.getSize().x) && (newX > 0)) player.setPosition(1, player.getPosition().y);
//		if ((player.getPosition().x <= 0) && (newX < 0)) player.setPosition(239, player.getPosition().y);
//		player.move(newX, 0);
//
//
//		//Testing
//		//sf::Font font;
//		//
//		//if (!font.loadFromFile("arial.ttf"))
//		//{
//		//	// error...
//		//}
//
//		//sf::Text text;
//		//text.setFont(font);
//		//text.setString("Hello World");
//		//text.setCharacterSize(40);
//		//text.setColor(sf::Color::White);
//
//
//
//
//		window.clear();
//		// Draw everything on the window
//		window.draw(background);
//		window.draw(player);
//		window.draw(p1);
//		window.draw(p2);
//		window.draw(p3);
//		window.draw(p4);
//		window.draw(p5);
//		//window.draw(text);
//		window.display();
//	}
//
//}