#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Object.hpp"



class Text : public Object
{
private:
	//Base* base;
	sf::Font* font;
	int x;
	int y;
	unsigned int size;
	unsigned int R;
	unsigned int G;
	unsigned int B;
	unsigned int A;
	bool bold;
	bool italic;
	bool underline;
	sf::Text text;
	std::string _text;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Cria o texto </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Text();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deleta o texto <see cref="Text"/>. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	~Text(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Carrega um arquivo de fonte para o texto </summary>
	/// <param name="filename">Caminho do arquivo de fonte a ser carregado (TrueType, Type 1, CFF, OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR, Type 42)</param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void load(std::string filename);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha o texto </summary>
	///
	/// <param name="text">			Texto a ser desenhado</param>
	/// <param name="x">			Posição do texto no eixo X</param>
	/// <param name="y">			Posição do texto no eixo Y </param>
	/// <param name="size">			(Opcional) Tamanho do texto em pixels, padrão é 10 px</param>
	/// <param name="R">			(Opcional) Cor vermelha (0-255), padrão é 255</param>
	/// <param name="G">			(Opcional) Cor verde (0-255), padrão é 255</param>
	/// <param name="B">			(Opcional) Cor Azul (0-255), padrão é 255</param>
	/// <param name="A">			(Opcional) Nível de Opacidade (0-255), padrão é 255</param>
	/// <param name="bold">			(Opcional) Negrito</param>
	/// <param name="italic">   	(Opcional) Italico</param>
	/// <param name="underline">	(Opcional) Sublinhado</param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void draw(std::string text, int x, int y, unsigned int size = 10, unsigned int R = 255, unsigned int G = 255, unsigned int B = 255, unsigned int A = 255, bool bold = false, bool italic = false, bool underline = false);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Desenha o Numero </summary>
	///
	/// <param name="text">			Numero a ser desenhado</param>
	/// <param name="x">			Posição do numero no eixo X</param>
	/// <param name="y">			Posição do numero no eixo Y </param>
	/// <param name="size">			(Opcional) Tamanho do numero em pixels, padrão é 10 px</param>
	/// <param name="R">			(Opcional) Cor vermelha (0-255), padrão é 255</param>
	/// <param name="G">			(Opcional) Cor verde (0-255), padrão é 255</param>
	/// <param name="B">			(Opcional) Cor Azul (0-255), padrão é 255</param>
	/// <param name="A">			(Opcional) Nível de Opacidade (0-255), padrão é 255</param>
	/// <param name="bold">			(Opcional) Negrito</param>
	/// <param name="italic">   	(Opcional) Italico</param>
	/// <param name="underline">	(Opcional) Sublinhado</param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void draw(int text, int x, int y, unsigned int size = 10, unsigned int R = 255, unsigned int G = 255, unsigned int B = 255, unsigned int A = 255, bool bold = false, bool italic = false, bool underline = false);
};