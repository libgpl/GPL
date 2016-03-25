#pragma once
#include <SFML/Graphics.hpp>
//#include "Text.hpp"


//struct Vector2
//{
//	float x, y;
//	Vector2(float x, float y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//};

static float distance(int aX, int aY, int bX, int bY)
{
	return sqrt(pow(aX - bX, 2) + pow(aY - bY, 2));
}

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

