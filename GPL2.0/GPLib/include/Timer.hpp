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

#include <SFML\Graphics.hpp>
#include <string>

class Timer
{
	sf::Clock relogio;
	sf::Time tempo;
	unsigned int hora;
	unsigned int minuto;
	unsigned int segundo;
	unsigned int time;
public:
	Timer();
	~Timer();

	//Retorna se o tempo terminou, esse método só serve se o tempo escolhido é do tipo cronômetro regressivo.
	bool timeEnded();

	void restart(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0);

	const std::string getTime();
	const unsigned int getHour();
	const unsigned int getMinute();
	const unsigned int getSecond();

	void setSecond(unsigned int seconds);
	void setMinute(unsigned int minutes);
	void setHour(unsigned int hours);
};