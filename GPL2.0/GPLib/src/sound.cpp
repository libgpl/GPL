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
#include "../include/Sound.hpp"
#include "../include/Window.hpp"

/// <summary>
/// Cria um arquivo de Sound <see cref="Sound"/>.
/// </summary>
Sound::Sound(void)
{
}

Sound::~Sound(void)
{
}

/// <summary>
/// Carrega um arquivo de Sound (ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam, w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64)
/// </summary>
/// <param name="arquivo">Caminho do arquivo de Sound a ser carregado</param>
void Sound::load(std::string Filename)
{
	std::string File = "./assets/sounds/" + Filename;
	if (!buffer.loadFromFile(File))
	{
		panel->debug("ERROR", "Arquivo de som '" + Filename + "' não encontrado");
	}

	_sound.setBuffer(buffer);
}

/// <summary>
/// Começa a tocar o Sound.
/// </summary>
/// <param name="volume">Define o volume do Sound.</param>
/// <param name="repetir">Define se o Sound deve repetir</param>
void Sound::play(int volume, bool repeat)
{
	if (isPlaying == false)
	{
		if (this->volume != volume) _sound.setVolume((float)volume);
		if (this->repeat != repeat) _sound.setLoop(repeat);
		_sound.play();
		isPlaying = true;
	}
}
/// <summary>
/// Pausa o Sound.
/// </summary>
void Sound::pause()
{
	isPlaying = false;
	_sound.pause();
}

/// <summary>
/// Para de tocar o Sound.
/// </summary>
void Sound::stop()
{
	isPlaying = false;
	_sound.stop();
}