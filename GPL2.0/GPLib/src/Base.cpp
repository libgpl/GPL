#include "../include/Base.h"


Base::Base(void)
{
	version = "v2.0.2-alpha";
}


Base::~Base(void)
{
}

void Base::setWindow(Window *window)
{
	this->window = window;
}
