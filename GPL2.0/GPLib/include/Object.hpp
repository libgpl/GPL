#pragma once
#include <SFML/Graphics.hpp>


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
	float deltaX = aX - bX;
	float deltaY = aY - bY;
	float angulo = atan(deltaX / deltaY) * (180 / 3.14159265359);

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
	return sqrt(pow(aX - bX, 2) + pow(aY - bY, 2));
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

