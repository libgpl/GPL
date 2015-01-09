#include "../include/Object.h"


Object::Object(void)
{
	defaultText = new Text();
	defaultText->load("calibri.ttf");
}


Object::~Object(void)
{
}
