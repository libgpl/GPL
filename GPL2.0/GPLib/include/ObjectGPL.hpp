#pragma once
#include <SFML/Graphics.hpp>
#include "Text.hpp"


class ObjectGPL
{
public:
	ObjectGPL(void);
	virtual ~ObjectGPL(void);
protected:
	Text defaultText;
private:
	int ID;
};

