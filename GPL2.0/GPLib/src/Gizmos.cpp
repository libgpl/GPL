#include "../include/Gizmos.hpp"


Gizmos::Gizmos()
{
}


Gizmos::~Gizmos(void)
{
}

void Gizmos::grid(int x, int y, int R, int G, int B, int A)
{
	qtdX = (base->getWindow()->getSize().x / x) + 1;
	qtdY = (base->getWindow()->getSize().y / y) + 1;

	for (int i = 0; i < qtdX; i++)
	{
		for (int j = 0; j < qtdY; j++)
		{
			pixel(i*x, -j*y + base->getWindow()->getSize().y, R, G, B, A);
			pixel(i*x + 1, -j*y + base->getWindow()->getSize().y, R, G, B, A);
			pixel(i*x, -j*y + 1 + base->getWindow()->getSize().y, R, G, B, A);
			pixel(i*x + 1, -j*y + 1 + base->getWindow()->getSize().y, R, G, B, A);
		}
	}
}


void Gizmos::pixel(int x, int y, int R, int G, int B, int A)
{
	sf::RectangleShape retangulo(sf::Vector2f(1,1));
	retangulo.setOutlineThickness(0);
	retangulo.setFillColor(sf::Color(R,G,B,A));
	retangulo.setOutlineColor(sf::Color(0,0,0,0));
	retangulo.setPosition((float)x,base->getWindow()->getSize().y-(float)y);
	base->getWindow()->draw(retangulo);
}

void Gizmos::line(int x, int y, int lenght, int thickness, int R, int G, int B, int A, int angle)
{
	sf::RectangleShape retangulo(sf::Vector2f((float)lenght, (float)thickness));
	retangulo.setOutlineThickness(0);
	retangulo.setFillColor(sf::Color(R, G, B, A));
	retangulo.setOutlineColor(sf::Color(0,0,0,0));
	retangulo.setPosition((float)x,base->getWindow()->getSize().y-(float)y);
	retangulo.setRotation((float)angle);
	base->getWindow()->draw(retangulo);
}

void Gizmos::rectangle(int x, int y, int widht, int height, int thickness, int R, int G, int B, int A, int angle)
{
	sf::RectangleShape retangulo(sf::Vector2f((float)widht, (float)height));
	retangulo.setOutlineThickness((float)thickness);
	retangulo.setFillColor(sf::Color(0,0,0,0));
	retangulo.setOutlineColor(sf::Color(R, G, B, A));
	retangulo.setPosition((float)x,base->getWindow()->getSize().y-(float)y);
	retangulo.setRotation((float)angle);
	base->getWindow()->draw(retangulo);
}

void Gizmos::circle(int x, int y, int radius, int thickness, int R, int G, int B, int A)
{
	sf::CircleShape shape((float)radius);
	shape.setFillColor(sf::Color(0,0,0,0));
	shape.setOutlineThickness((float)thickness);
	shape.setOutlineColor(sf::Color(R,G,B,A));
	shape.setPosition((float)x,base->getWindow()->getSize().y-(float)y);
	base->getWindow()->draw(shape);
}