#include"spiderstructure.h"


spider::spider(int nid)
{
	id = nid;
	pNext = nullptr;


	if (!tit.loadFromFile("spider.png"))
		cout << "Spider didn't load.\n";
	else
		it.setTexture(tit);
	it.setPosition(-50, -50);

	sf::Vector2f size(100, 90);
	sf::Vector2f position(-50, -50);

	setSize(size);
	setPosition(position);
}
spider::~spider()
{}


void spider::move(float offsetX, float offsetY)
{
	it.move(offsetX, offsetY);
}

void spider::setposition(float positionx, float positiony)
{
	it.setPosition(positionx, positiony);
	sf::Vector2f position(positionx, positiony);
	setPosition(position);

}

spider* spider::getnext()
{
	return pNext;
}


sf::Vector2f spider::getPosition()
{
	return it.getPosition();
}


void spider::draw(sf::RenderWindow &window)
{
	window.draw(it);
}

void spider::setnext(spider *next)
{
	pNext = next;
}

spider* spider::getprev()
{
	return pLast;
}

void spider::setprev(spider* prev)
{
	pLast = prev;
}

int spider::getid()
{
	return id;
}