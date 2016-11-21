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
#include <string>
#include <iostream>

#include "../SFML/include/SFML/Audio.hpp"
#include "Audio.hpp"

class Music : public Audio
{
private:
	sf::Music _music;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	/// Cria a m�sica <see cref="Music"/></summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Music(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deleta a m�sica <see cref="Music"/>. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	~Music(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Carrega um arquivo de m�sica
	/// </summary>
	/// <param name="Filename">	Caminho do arquivo da m�sica a ser carregado (ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam, w64,
	/// mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64) </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void load(std::string Filename) override;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Come�a a tocar a m�sica. </summary>
	/// <param name="volume">	(Opcional) Define o volume da m�sica, padr�o � 10. </param>
	/// <param name="repeat">	(Opcional) Define se a m�sica deve repetir, padr�o � n�o. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void play(int volume = 10, bool repeat = false) override;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Pausa a m�sica</summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void pause() override;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Pausa a m�sica </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void stop() override;
};