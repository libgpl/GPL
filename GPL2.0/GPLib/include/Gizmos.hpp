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

