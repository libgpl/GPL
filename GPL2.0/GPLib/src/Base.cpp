#include "../include/Base.h"

Base::Base(void)
{
	if(!single)
	{
		single = new Base(true);
	}
}
Base::~Base(void)
{
	if(single)
	{
		delete single;
	}
}
void Base::setWindow(Window *window)
{
	if(!single)
	{
		single = new Base(true);
	}
	single->window = window;
}

Window* Base::getWindow()
{
	if(!single)
	{
		single = new Base(true);
	}
	return single->window;
}

string Base::getVersion()
{
	return version;
}


Base *Base::single = 0;

