#include "../include/Sprite.hpp"
#include <vector>

#pragma once

struct vec2
{
	float x;
	float y;
};

struct painel
{
	std::vector<vec2> posXY;
	vec2 qtd;
	vec2 speed;
	Sprite imagem;
};

class Parallax
{
private:
	int x;
	int y;
	bool repeatX;
	bool repeatY;
	int windowWidth;
	int windowHeight;
	std::vector<painel*> panels;
public:
	Parallax(bool repeatX = false, bool repeatY = false);
	void addPanel(std::string sprite, float velX = 1.0, float velY = 1.0);
	void draw(int x, int y);

	~Parallax();
};

