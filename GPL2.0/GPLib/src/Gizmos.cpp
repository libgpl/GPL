/*
========================================================
GPL - Game Programming Library
by Luan Carlos Nesi (2014-2016)
https://github.com/libgpl
========================================================

The MIT License (MIT)

Copyright (c) 2014-2016 Luan Nesi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
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
	sf::RectangleShape retangulo(sf::Vector2f(1, 1));
	retangulo.setOutlineThickness(0);
	retangulo.setFillColor(sf::Color(R, G, B, A));
	retangulo.setOutlineColor(sf::Color(0, 0, 0, 0));
	retangulo.setPosition((float)x, (float)y);
	base->getWindow()->draw(retangulo);
}

void Gizmos::line(int x, int y, int lenght, int thickness, int R, int G, int B, int A, int angle)
{
	sf::RectangleShape retangulo(sf::Vector2f((float)lenght, (float)thickness));
	retangulo.setOutlineThickness(0);
	retangulo.setFillColor(sf::Color(R, G, B, A));
	retangulo.setOutlineColor(sf::Color(0, 0, 0, 0));
	retangulo.setPosition((float)x, base->getWindow()->getSize().y - (float)y);
	retangulo.setRotation((float)angle);
	base->getWindow()->draw(retangulo);
}

void Gizmos::line2(int x1, int y1, int x2, int y2, int R, int G, int B, int A)
{
	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f((float)x1,(float)y1),sf::Color(R, G, B, A)),
		sf::Vertex(sf::Vector2f((float)x2,(float)y2),sf::Color(R, G, B, A)),
	};

	base->getWindow()->draw(line2, 2, sf::Lines);
}

void Gizmos::rectangle(int x, int y, int widht, int height, int thickness, int R, int G, int B, int A, int angle)
{
	sf::RectangleShape retangulo(sf::Vector2f((float)widht, (float)height));
	retangulo.setOutlineThickness((float)thickness);
	retangulo.setFillColor(sf::Color(0, 0, 0, 0));
	retangulo.setOutlineColor(sf::Color(R, G, B, A));
	retangulo.setPosition((float)x, (float)y);
	retangulo.setRotation((float)angle);
	base->getWindow()->draw(retangulo);
}

void Gizmos::circle(int x, int y, int radius, int thickness, int R, int G, int B, int A)
{
	sf::CircleShape shape((float)radius);
	shape.setFillColor(sf::Color(0, 0, 0, 0));
	shape.setOutlineThickness((float)thickness);
	shape.setOutlineColor(sf::Color(R, G, B, A));
	shape.setPosition((float)x, (float)y);
	base->getWindow()->draw(shape);
}