#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <iostream>
#include "gplObj.h"

using namespace std;

class imagem : gplObj
{
private:
	int x;
	int y;
	unsigned int angulo;
	unsigned int animationTime;
	sf::Time timer;
	sf::Clock clk;
    int currentFrame;

	vector<sf::Texture*> frames;
public:
	sf::Sprite sprite;
	imagem(void);
	~imagem(void);
	void carregar(string arquivo);
	void carregar(string arquivo, unsigned int x, unsigned int y, unsigned int largura, unsigned int altura);
	void setVelocidade(unsigned int velocidade);
	int getVelocidade();
	int getResX();
	int getResY();
	void desenha(int x, int y, unsigned int angulo = 0, bool borda = false);
	void setFrame(int frame);
	bool colide(imagem img);
	int getPosX();
	int getPosY();

};