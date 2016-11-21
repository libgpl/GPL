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
#include "Object.hpp"
#include "Base.hpp"

class Gizmos : public Object
{
private:
	//Base* base;
public:
	int qtdX;
	int qtdY;
	Gizmos();
	~Gizmos(void);

	void grid(int x, int y, int R = 255, int G = 255, int B = 255, int A = 255);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha um pixel. </summary>
	///
	/// <param name="x">	Posição em X </param>
	/// <param name="y">	Posição em Y </param>
	/// <param name="R">	(Opcional) Cor vermelha (0 - 255), padrão = 255. </param>
	/// <param name="G">	(Opcional) Cor verde (0 - 255), padrão = 255. </param>
	/// <param name="B">	(Opcional) Cor azul (0 - 255), padrão = 255. </param>
	/// <param name="A">	(Opcional) Opacidade (0 - 255), padrão = 255. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void pixel(int x, int y, int R = 255, int G = 255, int B = 255, int A = 255);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha uma linha. </summary>
	///
	/// <param name="x">			Posição em X. </param>
	/// <param name="y">			Posição em Y. </param>
	/// <param name="lenght">   	Comprimento da linha. </param>
	/// <param name="thickness">	(Opcional) Espessura da linha, padrão = 1. </param>
	/// <param name="R">			(Opcional) Cor vermelha (0 - 255), padrão = 255. </param>
	/// <param name="G">			(Opcional) Cor verde (0 - 255), padrão = 255. </param>
	/// <param name="B">			(Opcional) Cor azul (0 - 255), padrão = 255. </param>
	/// <param name="A">			(Opcional) Opacidade (0 - 255), padrão = 255. </param>
	/// <param name="angle">		(Opcional) Ângulo, padrão = 0 (zero) </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void line(int x, int y, int lenght, int thickness = 1, int R = 255, int G = 255, int B = 255, int A = 255, int angle = 0);

	void line2(int x1, int y1, int x2, int y2, int R = 255, int G = 255, int B = 255, int A = 255);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha um retangulo. </summary>
	///
	/// <param name="x">			Posição em X. </param>
	/// <param name="y">			Posição em Y. </param>
	/// <param name="width">		Largura. </param>
	/// <param name="height">   	Altura. </param>
	/// <param name="thickness">	(Opcional) Espessura borda, padrão = 1. </param>
	/// <param name="R">			(Opcional) Cor vermelha (0 - 255), padrão = 255. </param>
	/// <param name="G">			(Opcional) Cor verde (0 - 255), padrão = 255. </param>
	/// <param name="B">			(Opcional) Cor azul (0 - 255), padrão = 255. </param>
	/// <param name="A">			(Opcional) Opacidade (0 - 255), padrão = 255. </param>
	/// <param name="angle">		(Opcional) Ângulo, padrão = 0 (zero) </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void rectangle(int x, int y, int width, int height, int thickness = 1, int R = 255, int G = 255, int B = 255, int A = 255, int angle = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha um círculo. </summary>
	///
	/// <param name="x">			Posição em X. </param>
	/// <param name="y">			Posição em Y. </param>
	/// <param name="radius">   	Raio do círculo. </param>
	/// <param name="thickness">	(Opcional) Espessura borda, padrão = 1. </param>
	/// <param name="R">			(Opcional) Cor vermelha (0 - 255), padrão = 255. </param>
	/// <param name="G">			(Opcional) Cor verde (0 - 255), padrão = 255. </param>
	/// <param name="B">			(Opcional) Cor azul (0 - 255), padrão = 255. </param>
	/// <param name="A">			(Opcional) Opacidade (0 - 255), padrão = 255. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void circle(int x, int y, int radius, int thickness = 1, int R = 255, int G = 255, int B = 255, int A = 255);
};