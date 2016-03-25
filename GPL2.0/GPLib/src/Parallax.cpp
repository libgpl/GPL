#include "../include/Parallax.hpp"


Parallax::~Parallax()
{
}


Parallax::Parallax(bool repeatX, bool repeatY) : x(0), y(0)
{
	this->repeatX = repeatX;
	this->repeatY = repeatY;


	windowHeight = base->getWindow()->getSize().y;
	windowWidth  = base->getWindow()->getSize().x;
}

void Parallax::addPanel(std::string sprite, float velX, float velY)
{
	panels.push_back(new painel);

	panels.back()->imagem.load(sprite);
	panels.back()->speed.x = velX;
	panels.back()->speed.y = velY;

	// TODO trocar dimensões pelos métodos da janela
	panels.back()->qtd.x = windowWidth / panels.back()->imagem.getResX();
	panels.back()->qtd.y = windowHeight / panels.back()->imagem.getResY();

	panels.back()->qtd.x += 2;
	panels.back()->qtd.y += 2;
	for (int i = 0; i < panels.back()->qtd.x; i++)
	{
		for (int j = 1; j <= panels.back()->qtd.y; j++)
		{
			panels.back()->posXY.push_back(vec2());
			panels.back()->posXY.back().x = i * panels.back()->imagem.getResX();
			panels.back()->posXY.back().y = j * panels.back()->imagem.getResY();
		}
	}
}

void Parallax::draw(int x, int y)
{
	if (this->x != x)
	{
		int dif = abs(this->x - x);
		for (int k = 0; k < panels.size(); k++)
		{
			for (int i = 0; i < panels.at(k)->posXY.size(); i++)
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
		for (int k = 0; k < panels.size(); k++)
		{
			for (int i = 0; i < panels.at(k)->posXY.size(); i++)
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
	for (int k = 0; k < panels.size(); k++)
	{
		for (int i = 0; i < panels.at(k)->posXY.size(); i++)
		{
			int xx = panels.at(k)->posXY[i].x + (panels.at(k)->qtd.x * panels.at(k)->imagem.getResX());
			int yy = panels.at(k)->posXY[i].y + (panels.at(k)->qtd.y * panels.at(k)->imagem.getResY());

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
			xx = panels.at(k)->posXY[i].x + (panels.at(k)->qtd.x * panels.at(k)->imagem.getResX());
			yy = panels.at(k)->posXY[i].y + (panels.at(k)->qtd.y * panels.at(k)->imagem.getResY());

			panels.at(k)->imagem.draw(xx, yy);
		}
	}
}
