#pragma once
#include <SFML/Graphics.hpp>
//#include "Text.hpp"


struct Vector2 final
{
	float x, y;
	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

float distance(Vector2 a, Vector2 b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

struct Vector3 final
{
	float x, y, z;
	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};


class Object
{
public:
	Object(void);
	virtual ~Object(void);
};

