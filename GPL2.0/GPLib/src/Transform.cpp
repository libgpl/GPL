#include "../include/Transform.hpp"


Transform::Transform(void):position(0,0),rotation(0),scale(1,1)
{
}


Transform::~Transform(void)
{
}

void Transform::setPosition(const float x, const float y)
{
	position.x = x;
	position.y = y;
}

void Transform::setPosition(const Vector2f position)
{
	this->position = position;
}

const float Transform::getPositionX()
{
	return position.x;
}

const float Transform::getPositionY()
{
	return position.y;
}

const Vector2f Transform::getPosition()
{
	return position;
}

void Transform::setRotation(const float angle)
{
	rotation = angle;
}

const float Transform::getRotation()
{
	return rotation;
}

void Transform::setScale(const float x, const float y)
{
	scale.x = x;
	scale.y = y;
}

void Transform::setScale(const Vector2f scale)
{
	this->scale = scale;
}

const float Transform::getScaleX()
{
	return scale.x;
}

const float Transform::getScaleY()
{
	return scale.y;
}

const Vector2f Transform::getScale()
{
	return scale;
}