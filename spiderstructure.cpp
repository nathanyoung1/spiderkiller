#include"spiderstructure.h"

spider::spider()
{
	killed = false;
	active = false;
	sf::Vector2f size(20, 5);
	position.x = -50;
	position.y = -50;

	body.setRadius(10.f);
	body.setPosition(position.x, position.y);
	body.setFillColor(sf::Color::Black);

	leg[0].setSize(size);
	leg[0].setRotation(320.f);
	leg[0].setPosition(position.x + 18.f, position.y + 5.f); // 90, 100
	leg[0].setFillColor(sf::Color::Black);

	leg[1].setSize(size);
	leg[1].setRotation(335.f);
	leg[1].setPosition(position.x + 18.f, position.y + 7.f); // 90, 102
	leg[1].setFillColor(sf::Color::Black);

	leg[2].setSize(size);
	leg[2].setRotation(355.f);
	leg[2].setPosition(position.x + 18.f, position.y + 9.f); // 90, 104
	leg[2].setFillColor(sf::Color::Black);

	leg[3].setSize(size);
	leg[3].setRotation(5.f);
	leg[3].setPosition(position.x + 18.f, position.y + 13.f); // 90, 108
	leg[3].setFillColor(sf::Color::Black);

	leg[4].setSize(size);
	leg[4].setRotation(220.f);
	leg[4].setPosition(position.x, position.y + 7.f); // 72, 102
	leg[4].setFillColor(sf::Color::Black);

	leg[5].setSize(size);
	leg[5].setRotation(205.f);
	leg[5].setPosition(position.x + 1.f, position.y + 12.f); // 73, 107
	leg[5].setFillColor(sf::Color::Black);

	leg[6].setSize(size);
	leg[6].setRotation(185.f);
	leg[6].setPosition(position.x + 3.f, position.y + 14.f); // 75, 109
	leg[6].setFillColor(sf::Color::Black);

	leg[7].setSize(size);
	leg[7].setRotation(170.f);
	leg[7].setPosition(position.x + 3.f, position.y + 18.f); //75, 113
	leg[7].setFillColor(sf::Color::Black);

	size.x = 30;
	size.y = 5;


	leg[8].setSize(size);
	leg[8].setRotation(20.f);
	leg[8].setPosition(position.x + 35.f, position.y - 9.f); // 107, 86
	leg[8].setFillColor(sf::Color::Black);

	leg[9].setSize(size);
	leg[9].setRotation(30.f);
	leg[9].setPosition(position.x + 38.f, position.y - 1.f); // 110, 94
	leg[9].setFillColor(sf::Color::Black);

	leg[10].setSize(size);
	leg[10].setRotation(55.f); // 355
	leg[10].setPosition(position.x + 40.f, position.y + 7.f); // 112, 102
	leg[10].setFillColor(sf::Color::Black);

	leg[11].setSize(size);
	leg[11].setRotation(95.f); // 5
	leg[11].setPosition(position.x + 39.f, position.y + 15.f); // 111, 110
	leg[11].setFillColor(sf::Color::Black);

	leg[12].setSize(size);
	leg[12].setRotation(160.f);
	leg[12].setPosition(position.x - 9.f, position.y - 5.f); //63, 90
	leg[12].setFillColor(sf::Color::Black);

	leg[13].setSize(size);
	leg[13].setRotation(150.f);
	leg[13].setPosition(position.x - 14.f, position.y + 2.f); //58, 97
	leg[13].setFillColor(sf::Color::Black);

	leg[14].setSize(size);
	leg[14].setRotation(125.f);
	leg[14].setPosition(position.x - 14.f, position.y + 10.f); //58, 105
	leg[14].setFillColor(sf::Color::Black);

	leg[15].setSize(size);
	leg[15].setRotation(85.f);
	leg[15].setPosition(position.x - 12.f, position.y + 15.f); // 60, 110
	leg[15].setFillColor(sf::Color::Black);
}
spider::~spider()
{}

sf::RectangleShape spider::getleg(int which)
{
	return leg[which];
}
sf::CircleShape spider::getbody()
{
	return body;
}

void spider::move(float offsetX, float offsetY)
{
	int i = 0;
	for (i = 0; i < 16; i++)
		leg[i].move(offsetX, offsetY);
	body.move(offsetX, offsetY);
}

void spider::setposition(float positionx, float positiony)
{
	position.x = positionx;
	position.y = positiony;
	// 72, 95
	body.setPosition(positionx, positiony);

	leg[0].setPosition(positionx + 18.f, positiony + 5.f); // 90, 100
	leg[1].setPosition(positionx + 18.f, positiony + 7.f); // 90, 102
	leg[2].setPosition(positionx + 18.f, positiony + 9.f); // 90, 104
	leg[3].setPosition(positionx + 18.f, positiony + 13.f); // 90, 108
	leg[4].setPosition(positionx, positiony + 7.f); // 72, 102
	leg[5].setPosition(positionx + 1.f, positiony + 12.f); // 73, 107
	leg[6].setPosition(positionx + 3.f, positiony + 14.f); // 75, 109
	leg[7].setPosition(positionx + 3.f, positiony + 18.f); //75, 113
	leg[8].setPosition(positionx + 35.f, positiony - 9.f); // 107, 86
	leg[9].setPosition(positionx + 38.f, positiony - 1.f); // 110, 94
	leg[10].setPosition(positionx + 40.f, positiony + 7.f); // 112, 102
	leg[11].setPosition(positionx + 39.f, positiony + 15.f); // 111, 110
	leg[12].setPosition(positionx - 9.f, positiony - 5.f); //63, 90
	leg[13].setPosition(positionx - 14.f, positiony + 2.f); //58, 97
	leg[14].setPosition(positionx - 14.f, positiony + 10.f); //58, 105
	leg[15].setPosition(positionx - 12.f, positiony + 15.f); // 60, 110
}

sf::Vector2i spider::getPosition()
{
	return position;
}

bool spider::iskilled()
{
	return killed;
}

void spider::kill()
{
	killed = true;
	active = false;
	this->setposition(-50, -50);
}

bool spider::isactive()
{
	return active;
}

void spider::activate()
{
	active = true;
}
