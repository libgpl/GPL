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

//#define STRINGIZE_HELPER(x) #x
//#define STRINGIZE(x) STRINGIZE_HELPER(x)
//#define __MESSAGE(text) __pragma( message(__FILE__ "(" STRINGIZE(__LINE__) ")" text) )
//#define WARNING(text) __MESSAGE( " : Warning: " #text )
//#define ERROR(text) __MESSAGE( " : Error: " #text )
//#define MESSAGE(text) __MESSAGE( ": " #text )
//#define TODO(text) WARNING( TODO: text )

//struct Vector2
//{
//	float x, y;
//	Vector2(float x, float y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//};

static float angle(int aX, int aY, int bX, int bY)
{
	int deltaX = aX - bX;
	int deltaY = aY - bY;
	float angulo = atan((float)deltaX / (float)deltaY) * (180.0f / 3.14159265359f);

	if (deltaY > 0)
	{
		angulo = angulo + 90;
	}
	else
	{
		angulo = angulo + 270;
	}

	return angulo;
}

static float distance(int aX, int aY, int bX, int bY)
{
	return (float)sqrt(pow(aX - bX, 2) + pow(aY - bY, 2));
}

#define VNAME(x) #x

//struct Vector3 final
//{
//	float x, y, z;
//	Vector3(float x, float y, float z)
//	{
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//};

class Object
{
public:
	Object(void);
	virtual ~Object(void);
};