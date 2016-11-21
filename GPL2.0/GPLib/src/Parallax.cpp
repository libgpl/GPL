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
#include "../include/Parallax.hpp"

Parallax::~Parallax()
{
}

Parallax::Parallax(bool repeatX, bool repeatY) : x(0), y(0)
{
	this->repeatX = repeatX;
	this->repeatY = repeatY;

	windowHeight = base->getWindow()->getSize().y;
	windowWidth = base->getWindow()->getSize().x;
}

void Parallax::addPanel(std::string sprite, float velX, float velY)
{
	panels.push_back(new painel);

	panels.back()->imagem.load(sprite);
	panels.back()->speed.x = velX;
	panels.back()->speed.y = velY;

	// TODO trocar dimensões pelos métodos da janela
	panels.back()->qtd.x = (float)windowWidth / panels.back()->imagem.getResX();
	panels.back()->qtd.y = (float)windowHeight / panels.back()->imagem.getResY();

	panels.back()->qtd.x += 2;
	panels.back()->qtd.y += 2;
	for (int i = 0; i < panels.back()->qtd.x; i++)
	{
		for (unsigned int j = 1; j <= panels.back()->qtd.y; j++)
		{
			panels.back()->posXY.push_back(vec2());
			panels.back()->posXY.back().x = (float)i * panels.back()->imagem.getResX();
			panels.back()->posXY.back().y = (float)j * panels.back()->imagem.getResY();
		}
	}
}

void Parallax::draw(int x, int y)
{
	if (this->x != x)
	{
		int dif = abs(this->x - x);
		for (unsigned int k = 0; k < panels.size(); k++)
		{
			for (unsigned int i = 0; i < panels.at(k)->posXY.size(); i++)
			{
				if (this->x < x)
				{
					panels.at(k)->posXY[i].x += (dif * panels.at(k)->speed.x);
				}
				else if (this->x > x)
				{
					panels.at(k)->posXY[i].x -= (dif * panels.at(k)->speed.x);
				}
			}
		}
		this->x = x;
	}
	if (this->y != y)
	{
		int dif = abs(this->y - y);
		for (unsigned int k = 0; k < panels.size(); k++)
		{
			for (unsigned int i = 0; i < panels.at(k)->posXY.size(); i++)
			{
				if (this->y < y)
				{
					panels.at(k)->posXY[i].y += (dif * panels.at(k)->speed.y);
				}
				else if (this->y > y)
				{
					panels.at(k)->posXY[i].y -= (dif * panels.at(k)->speed.y);
				}
			}
		}
		this->y = y;
	}

	// Repetições dos painéis
	for (unsigned int k = 0; k < panels.size(); k++)
	{
		for (unsigned int i = 0; i < panels.at(k)->posXY.size(); i++)
		{
			int xx = (int)(panels.at(k)->posXY[i].x + (panels.at(k)->qtd.x * panels.at(k)->imagem.getResX()));
			int yy = (int)(panels.at(k)->posXY[i].y + (panels.at(k)->qtd.y * panels.at(k)->imagem.getResY()));

			if (repeatX)
			{
				if (xx <= -panels.at(k)->imagem.getResX())
				{
					panels.at(k)->posXY[i].x += (panels.at(k)->qtd.x * panels.at(k)->imagem.getResX());
				}
				else if (xx > windowWidth)
				{
					panels.at(k)->posXY[i].x -= (panels.at(k)->qtd.x * panels.at(k)->imagem.getResX());
				}
			}

			if (repeatY)
			{
				if (yy <= 0)
				{
					panels.at(k)->posXY[i].y += (panels.at(k)->qtd.y * panels.at(k)->imagem.getResY());
				}
				else if (yy >= windowHeight + panels.at(k)->imagem.getResY())
				{
					panels.at(k)->posXY[i].y -= (panels.at(k)->qtd.y * panels.at(k)->imagem.getResY());
				}
			}
			xx = (int)(panels.at(k)->posXY[i].x + (panels.at(k)->qtd.x * panels.at(k)->imagem.getResX()));
			yy = (int)(panels.at(k)->posXY[i].y + (panels.at(k)->qtd.y * panels.at(k)->imagem.getResY()));

			panels.at(k)->imagem.draw(xx, yy);
		}
	}
}