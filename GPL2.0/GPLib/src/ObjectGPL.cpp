#include "../include/ObjectGPL.hpp"

static int GID = 0;

ObjectGPL::ObjectGPL(void)
{
	GID++;
	ID = GID;
	//defaultText = new Text();
	defaultText.load("calibri.ttf");
}


ObjectGPL::~ObjectGPL(void)
{
}
