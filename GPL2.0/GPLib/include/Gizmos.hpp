#pragma once
#include "Object.hpp"
#include "Base.hpp"

class Gizmos : public Object
{
private:
	//Base* base;
public:
	Gizmos();
	~Gizmos(void);
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha um pixel. </summary>
	///
	/// <param name="x">	Posi��o em X </param>
	/// <param name="y">	Posi��o em Y </param>
	/// <param name="R">	(Opcional) Cor vermelha (0 - 255), padr�o = 255. </param>
	/// <param name="G">	(Opcional) Cor verde (0 - 255), padr�o = 255. </param>
	/// <param name="B">	(Opcional) Cor azul (0 - 255), padr�o = 255. </param>
	/// <param name="A">	(Opcional) Opacidade (0 - 255), padr�o = 255. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void pixel(int x, int y, int R = 255, int G = 255, int B = 255, int A = 255);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha uma linha. </summary>
	///
	/// <param name="x">			Posi��o em X. </param>
	/// <param name="y">			Posi��o em Y. </param>
	/// <param name="lenght">   	Comprimento da linha. </param>
	/// <param name="thickness">	(Opcional) Espessura da linha, padr�o = 1. </param>
	/// <param name="R">			(Opcional) Cor vermelha (0 - 255), padr�o = 255. </param>
	/// <param name="G">			(Opcional) Cor verde (0 - 255), padr�o = 255. </param>
	/// <param name="B">			(Opcional) Cor azul (0 - 255), padr�o = 255. </param>
	/// <param name="A">			(Opcional) Opacidade (0 - 255), padr�o = 255. </param>
	/// <param name="angle">		(Opcional) �ngulo, padr�o = 0 (zero) </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void line(int x, int y, int lenght, int thickness = 1, int R = 255, int G = 255, int B = 255, int A = 255, int angle = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha um retangulo. </summary>
	///
	/// <param name="x">			Posi��o em X. </param>
	/// <param name="y">			Posi��o em Y. </param>
	/// <param name="width">		Largura. </param>
	/// <param name="height">   	Altura. </param>
	/// <param name="thickness">	(Opcional) Espessura borda, padr�o = 1. </param>
	/// <param name="R">			(Opcional) Cor vermelha (0 - 255), padr�o = 255. </param>
	/// <param name="G">			(Opcional) Cor verde (0 - 255), padr�o = 255. </param>
	/// <param name="B">			(Opcional) Cor azul (0 - 255), padr�o = 255. </param>
	/// <param name="A">			(Opcional) Opacidade (0 - 255), padr�o = 255. </param>
	/// <param name="angle">		(Opcional) �ngulo, padr�o = 0 (zero) </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void rectangle(int x, int y, int width, int height, int thickness = 1, int R = 255, int G = 255, int B = 255, int A = 255, int angle = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha um c�rculo. </summary>
	///
	/// <param name="x">			Posi��o em X. </param>
	/// <param name="y">			Posi��o em Y. </param>
	/// <param name="radius">   	Raio do c�rculo. </param>
	/// <param name="thickness">	(Opcional) Espessura borda, padr�o = 1. </param>
	/// <param name="R">			(Opcional) Cor vermelha (0 - 255), padr�o = 255. </param>
	/// <param name="G">			(Opcional) Cor verde (0 - 255), padr�o = 255. </param>
	/// <param name="B">			(Opcional) Cor azul (0 - 255), padr�o = 255. </param>
	/// <param name="A">			(Opcional) Opacidade (0 - 255), padr�o = 255. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void circle(int x, int y, int radius, int thickness = 1, int R = 255, int G = 255, int B = 255, int A = 255);

};

