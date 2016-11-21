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
#include "../include/Timer.hpp"

Timer::Timer() : hora(0), minuto(0), segundo(0), time(0)
{
	tempo.Zero;
	relogio.restart();
	tempo = relogio.getElapsedTime();
}

void Timer::restart(unsigned int hour, unsigned int minute, unsigned int second)
{
	tempo.Zero;
	relogio.restart();
	tempo = relogio.getElapsedTime();
	this->hora = hour;
	this->minuto = minute;
	this->segundo = second;
	this->time = (hour * 60 + minute) * 60 + second;
}

void Timer::setHour(unsigned int hours)
{
	this->hora = hours;
	this->time = (hora * 60 + minuto) * 60 + segundo;
}

void Timer::setMinute(unsigned int minutes)
{
	this->minuto = minutes;
	this->time = (hora * 60 + minuto) * 60 + segundo;
}

void Timer::setSecond(unsigned int seconds)
{
	this->segundo = seconds;
	this->time = (hora * 60 + minuto) * 60 + segundo;
}

bool Timer::timeEnded()
{
	// Contador regressivo
	if (time - tempo.asSeconds() > 0)
	{
		tempo = relogio.getElapsedTime();
		return false;
	}
	relogio.restart();
	return true;
}

Timer::~Timer()
{
}

const std::string Timer::getTime()
{
	tempo = relogio.getElapsedTime();
	int t = tempo.asMilliseconds();
	int hours = t / 3600000;
	t -= hours * 3600000;
	int minutes = t / 60000;
	t -= minutes * 60000;
	int seconds = t / 1000;

	if (hours + this->hora == 23 && minutes + minuto == 59 && seconds + segundo == 60)
	{
		this->hora = 0;
		this->minuto = 0;
		this->segundo = 0;
		relogio.restart();
	}

	std::string hora = std::to_string(hours + this->hora) + " : " + std::to_string(minutes + minuto) + " : " + std::to_string(seconds + segundo) + " s";
	return hora;
}

const unsigned int Timer::getHour()
{
	return hora;
}

const unsigned int Timer::getMinute()
{
	return minuto;
}

const unsigned int Timer::getSecond()
{
	return segundo;
}