#pragma once

#include "../include/Sprite.hpp"
#include "../include/Collision.hpp"
//#include "../include/Panel.hpp"

using namespace Collision;

Sprite::Sprite(void) :x(0), currentFrame(0), animationTime(30), alpha(255), mirror(false), x_pivot(0), y_pivot(0)
{

	y = 0;// base->getWindow()->getSize().y;
}

Sprite::~Sprite(void)
{
}

void Sprite::load(std::string Filename)
{
	frames.push_back(new sf::Texture());

	std::string File = "./assets/sprites/" + Filename;
	if(!(*frames.back()).loadFromFile(File))
	{
		std::string tete = "Arquivo do sprite '"+Filename+"' não encontrado";
		panel->debug("ERROR",tete);
	}		
}

void Sprite::loadSpriteSheet(std::string Filename, int qtdX, int qtdY)
{
	Sprite temp;
	temp.load(Filename);

	int FrameSizeX = temp.getResX() / qtdX;
	int FrameSizeY = temp.getResY() / qtdY;


	std::string File = "./assets/sprites/" + Filename;

	// Carrega várias imagens para criar uma animação fazendo cortes em um sprite sheet
	for (int j = 0; j < qtdY; j++)
	{
		for (int i = 0; i < qtdX; i++)
		{
			frames.push_back(new sf::Texture());
			if (!(*frames.back()).loadFromFile(File, sf::IntRect(FrameSizeX * i, FrameSizeY * j, FrameSizeX, FrameSizeY)))
			{
				std::string tete = "Arquivo do sprite '" + Filename + "' não encontrado";
				panel->debug("ERROR", tete);
			}
		}
	}
}
void Sprite::load(std::string Filename, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	frames.push_back(new sf::Texture());

	std::string File = "./assets/sprites/" + Filename;
	if(!(*frames.back()).loadFromFile(File, sf::IntRect(x, y, width, height)))
	{
		std::string tete = "Arquivo do sprite '"+Filename+"' não encontrado";
		panel->debug("ERROR",tete);
	}	
}

int Sprite::getResX() const
{
	return (*frames.back()).getSize().x;
}

int Sprite::getResY() const
{
	return (*frames.back()).getSize().y;
}

void Sprite::setSpeed(unsigned int speed)
{
	animationTime = speed;
}

int Sprite::getSpeed() const
{
	return animationTime;
}

void Sprite::setFrame(int frame)
{
	currentFrame = frame;
}

int Sprite::getFrame()
{
	return currentFrame;
}


void Sprite::draw(int x, int y, float scaleX, float scaleY, int pivotX, int pivotY, unsigned int alpha, unsigned int angle, bool edge)
{
	// Define a opacidade da imagem
	{
		// Aplica os limites inferior e superior para alpha (0-255)
		this->alpha = (this->alpha < 0) ? 0 : alpha;
		this->alpha = (this->alpha > 255) ? 255 : alpha;

		_sprite.setColor(sf::Color(255, 255, 255, this->alpha));
	}

	_sprite.setTexture((*frames.at(currentFrame)));

	timer = clk.getElapsedTime();

	if (timer.asMilliseconds() > animationTime)
	{
		currentFrame++;
		if (currentFrame == frames.size()) currentFrame = 0;
		clk.restart();
	}

	if (this->x_pivot != pivotX || this->y_pivot != pivotY)
	{
		this->x_pivot = pivotX;
		this->y_pivot = pivotY;
		_sprite.setOrigin(x_pivot,y_pivot);
	}

	if (this->x_scale != scaleX || this->y_scale != scaleY)
	{
		this->x_scale = scaleX;
		this->y_scale = scaleY;
		_sprite.setScale(scaleX, scaleY);
	}

	if (this->angle != angle)
	{
		while (angle > 360)
		{
			angle -= 360;
		}
		while (angle < 0)
		{
			angle += 360;
		}

		this->angle = angle;
		_sprite.setRotation((float)this->angle); // absolute angle
	}

	if (this->x != x || this->y != y)
	{
		this->x = x;
		this->y = y;
		_sprite.setPosition(sf::Vector2f((float)x, base->getWindow()->getSize().y - (float)y));
	}

	if (edge)
	{
		sf::RectangleShape retangulo(sf::Vector2f((float)((*_sprite.getTexture()).getSize().x), (float)(*_sprite.getTexture()).getSize().y));
		retangulo.setOutlineThickness((float)3);
		retangulo.setFillColor(sf::Color(0, 0, 0, 0));
		retangulo.setOutlineColor(sf::Color(255, 0, 0));
		retangulo.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);
		retangulo.setRotation(_sprite.getRotation());
		retangulo.setScale(scaleX, scaleY);
		retangulo.setOrigin(x_pivot, y_pivot);
		base->getWindow()->draw(retangulo);
	}

	base->getWindow()->draw(_sprite);
}


//void Sprite::draw(int x, int y, bool mirror, unsigned int alpha, unsigned int angle, bool edge)
//{
//	// Define a opacidade da imagem
//	{
//		// Aplica os limites inferior e superior para alpha (0-255)
//		this->alpha = (this->alpha < 0) ? 0 : alpha;
//		this->alpha = (this->alpha > 255) ? 255 : alpha;
//
//		_sprite.setColor(sf::Color(255,255,255,this->alpha));
//	}
//
//	// Habilita o desenho da imagem espelhado
// 	if(this->mirror != mirror)
//	{
//		this->mirror = mirror;
//		if(this->mirror)
//		{
//			_sprite.setScale(-1,1);
//		}
//		else
//		{
//			_sprite.setScale(1,1);
//		}
//	}
//	_sprite.setTexture((*frames.at(currentFrame)));
//
//	timer = clk.getElapsedTime();
//
//	if(timer.asMilliseconds() > animationTime)
//	{
//		currentFrame++;
//		if(currentFrame == frames.size()) currentFrame = 0;
//		clk.restart();
//	}
//
//	if (this->angle != angle)
//	{
//		while (angle > 360)
//		{
//			angle -= 360;
//		}
//		while (angle < 0)
//		{
//			angle += 360;
//		}
//
//		this->angle = angle;
//		_sprite.setOrigin(getResX() / 2, getResY() / 2);		// Define the center of the sprite as pivot
//		_sprite.setRotation((float)this->angle); // absolute angle
//	}
//
//	if(this->x != x || this->y != y)
//	{
//		this->x = x;
//		this->y = y;
//		_sprite.setPosition(sf::Vector2f((float)x,base->getWindow()->getSize().y-(float)y));
//	}
//
//	if(edge)
//	{
//		sf::RectangleShape retangulo(sf::Vector2f((float)((*_sprite.getTexture()).getSize().x),(float)(*_sprite.getTexture()).getSize().y));
//		retangulo.setOutlineThickness((float)3);
//		retangulo.setFillColor(sf::Color(0,0,0,0));
//		retangulo.setOutlineColor(sf::Color(255, 0, 0));
//		retangulo.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);
//		retangulo.setRotation(_sprite.getRotation());
//		retangulo.setScale(x_scale, y_scale);
//		retangulo.setOrigin(x_pivot, y_pivot);
//		base->getWindow()->draw(retangulo);
//	}
//
//	base->getWindow()->draw(_sprite);
//}

bool Sprite::collides(Sprite _sprite)
{
	// Método de colisão adaptado da LibEGL
	int w1 = getResX();
	int h1 = getResY();
	int x1 = x;
	int y1 = y;

	int w2 = _sprite.getResX();
	int h2 = _sprite.getResY();
	int x2 = _sprite.x;
	int y2 = _sprite.y;

	if(BoundingBoxTest(this->_sprite,_sprite._sprite))
	{
		return PixelPerfectTest(this->_sprite,_sprite._sprite);
	}
	else
	{
		return false;
	}
}

int Sprite::getPosX() const
{
	return x;
}

int Sprite::getPosY() const
{
	return y;
}