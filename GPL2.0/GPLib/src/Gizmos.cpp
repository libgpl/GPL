#include "../include/Gizmos.hpp"s


Gizmos::Gizmos()
{
}


Gizmos::~Gizmos(void)
{
}

void Gizmos::pixel(int x, int y, int R, int G, int B, int A)
{
	sf::RectangleShape retangulo(sf::Vector2f(1,1));
	retangulo.setOutlineThickness(0);
	retangulo.setFillColor(sf::Color(R,G,B,A));
	retangulo.setOutlineColor(sf::Color(0,0,0,0));
	retangulo.setPosition((float)x,(float)y);
	base->getWindow()->draw(retangulo);
}

void Gizmos::line(int x, int y, int lenght, int thickness, int R, int G, int B, int A, int angle)
{
	sf::RectangleShape retangulo(sf::Vector2f((float)lenght, (float)thickness));
	retangulo.setOutlineThickness(0);
	retangulo.setFillColor(sf::Color(R, G, B, A));
	retangulo.setOutlineColor(sf::Color(0,0,0,0));
	retangulo.setPosition((float)x,(float)y);
	retangulo.setRotation((float)angle);
	base->getWindow()->draw(retangulo);
}

void Gizmos::rectangle(int x, int y, int widht, int height, int thickness, int R, int G, int B, int A, int angle)
{
	sf::RectangleShape retangulo(sf::Vector2f((float)widht, (float)height));
	retangulo.setOutlineThickness((float)thickness);
	retangulo.setFillColor(sf::Color(0,0,0,0));
	retangulo.setOutlineColor(sf::Color(R, G, B, A));
	retangulo.setPosition((float)x,(float)y);
	retangulo.setRotation((float)angle);
	base->getWindow()->draw(retangulo);
}

void Gizmos::circle(int x, int y, int radius, int thickness, int R, int G, int B, int A)
{
	sf::CircleShape shape((float)radius);
	shape.setFillColor(sf::Color(0,0,0,0));
	shape.setOutlineThickness((float)thickness);
	shape.setOutlineColor(sf::Color(R,G,B,A));
	shape.setPosition((float)x,(float)y);
	base->getWindow()->draw(shape);
}