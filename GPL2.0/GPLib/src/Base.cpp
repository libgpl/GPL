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
#include "../include/Base.hpp"

Base::Base(void) : version("3.1.72")
{
	defaultText = new Text();
	defaultText->load("..\\..\\..\\..\\GPLib\\resources\\calibri.ttf");
}

Base* Base::getInstance()
{
	if (!instance)
	{
		instance = new Base();
	}
	return instance;
}

Base::~Base(void)
{
	if (instance)
	{
		delete instance;
	}
}
void Base::setWindow(_Window* window)
{
	getInstance();
	instance->window = window;
}

_Window* Base::getWindow() const
{
	getInstance();
	if (instance->window == NULL)
	{
		return NULL;
	}
	return instance->window;
}

std::string Base::getVersion() const
{
	getInstance();
	return version;
}

Base *Base::instance = NULL;