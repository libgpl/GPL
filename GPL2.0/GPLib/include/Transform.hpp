#pragma once
#include "SFML/Graphics.hpp"
typedef sf::Vector2f Vector2f;

class Transform
{
private:
	Vector2f position;
	float rotation;
	Vector2f scale;
public:
	Transform(void);
	~Transform(void);

	void setPosition(const float x, const float y);
	void setPosition(const Vector2f position);
	const float getPositionX();
	const float getPositionY();
	const Vector2f getPosition();

	void setRotation(const float angle);
	const float getRotation();

	void setScale(const float x, const float y);
	void setScale(const Vector2f position);
	const float getScaleX();
	const float getScaleY();
	const Vector2f getScale();

};

