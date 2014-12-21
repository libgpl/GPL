#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "gplObj.h"

using namespace std;

class texto : gplObj
{
private: 
	sf::Font *font;
	int x;
	int y;
	unsigned int tamanho;
	unsigned int R;
	unsigned int G;
	unsigned int B;
	unsigned int A;
	bool negrito;
	bool italico;
	bool sublinhado;
	sf::Text Text;
	string _text;
public:
	texto();
	~texto(void);
	void carregar(string arquivo);
	void desenha(string texto, int x, int y, unsigned int tamanho = 10, unsigned int R = 255, unsigned int G = 255, unsigned int B = 255, unsigned int A = 255, bool negrito = false, bool italico = false, bool sublinhado = false);
};

