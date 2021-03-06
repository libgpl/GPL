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

#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <iostream>
#include "Object.hpp"
#include "Panel.hpp"
#include "Base.hpp"

//#include "../include/gpl.hpp"

class Sprite : public Object
{
private:
	//Panel* panel;
	//Base* base;
	int x_pivot;
	int y_pivot;
	int x_scale;
	int y_scale;
	int x;
	int y;
	int alpha;
	bool mirror;
	unsigned int angle;
	unsigned int animationTime;
	sf::Time timer;
	sf::Clock clk;
	int currentFrame;
	Text text;
	std::string filename;

	std::vector<sf::Texture*> frames;
	sf::Sprite _sprite;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Cria o sprite <see cref="Sprite"/>. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Sprite(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deleta o sprite <see cref="Sprite"/>. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	~Sprite(void);

	void loadSpriteSheet(std::string Filename, int qtdX, int qtdY);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Carrega arquivo de sprite </summary>
	/// <param name="Filename">	Caminho do arquivo da sprite a ser carregado (bmp, png, tga, jpg, gif, psd, hdr, pic)</param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void load(std::string Filename);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Carrega parte de um arquivo de sprite
	/// </summary>
	/// <param name="Filename">	Caminho do arquivo da sprite a ser carregado (bmp, png, tga, jpg, gif, psd, hdr, pic)</param>
	/// <param name="x">	   	Posi��o X de inicio do recorte. </param>
	/// <param name="y">	   	Posi��o Y de inicio do recorte. </param>
	/// <param name="width">   	Largura do recorte. </param>
	/// <param name="height">  	Altura do recorte. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void load(std::string Filename, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Define a velocidade da anima��o, ou seja, o tempo que cada frame ser� exibido, padr�o e 30.
	/// </summary>
	/// <param name="speed">	velocidade dos frames. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void setSpeed(unsigned int speed);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Retorna a velocidade da anima��o, se n�o alterado o valor padr�o � 30 </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getSpeed() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna a largura do sprite</summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getResX() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna a altura do sprite</summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getResY() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha o sprite. </summary>	///
	/// <param name="x">	 	Posi��o X. </param>
	/// <param name="y">	 	Posi��o Y. </param>
	/// <param name="scaleX">	Escala X. </param>
	/// <param name="scaleY">	Escala Y. </param>
	/// <param name="pivotX">	Piv� X. </param>
	/// <param name="pivotY">	Piv� Y. </param>
	/// <param name="alpha"> 	(Optional) Transpar�ncia </param>
	/// <param name="angle"> 	(Opcional) angulo, padr�o � 0. </param>
	/// <param name="edge">  	(Opcional) desenhar borda no sprite, padr�o � n�o. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void draw(int x, int y, float scaleX = 1.0, float scaleY = 1.0, int pivotX = 0, int pivotY = 0, unsigned int alpha = 255, unsigned int angle = 0, bool edge = false);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	///// <summary>	Desenha o sprite. </summary>	///
	///// <param name="x">	 	Posi��o X. </param>
	///// <param name="y">	 	Posi��o Y. </param>
	///// <param name="mirror">	(Optional) Espelhamento </param>
	///// <param name="alpha"> 	(Optional) Transpar�ncia </param>
	///// <param name="angle"> 	(Optional) angulo, padr�o � 0. </param>
	///// <param name="edge">  	(Optional) desenhar borda no sprite, padr�o � n�o. </param>
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	//void draw(int x, int y, bool mirror = false, unsigned int alpha = 255, unsigned int angle = 0, bool edge = false);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Set a frame. </summary>
	///
	/// <remarks>	Nesi, 03/09/2014. </remarks>
	///
	/// <param name="frame">	The frame. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void setFrame(int frame);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the current frame. </summary>
	///
	/// <remarks>	Nesi, 19/02/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int Sprite::getFrame();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Verifica se o sprite colidiu com outro sprite. </summary>
	///
	///
	/// <param name="_sprite">	Sprite a ser verificada se houve colis�o. </param>
	///
	/// <returns> se houve colis�o retorna true, caso contr�rio retorna falso</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	bool collides(Sprite _sprite);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna a posi��o do sprite no eixo X. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getPosX() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna a posi��o do sprite no eixo Y. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getPosY() const;
};