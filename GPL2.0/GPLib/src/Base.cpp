#include "../include/Base.hpp"

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
void Base::setWindow(_Window* window)
{
	if(!single)
	{
		single = new Base(true);
	}
	single->window = window;
}

_Window* Base::getWindow() const
{
	if(&single->window == NULL)
	{
		return NULL;
	}
	return single->window;
}

std::string Base::getVersion() const
{
	return version;
}


Base* Base::single = 0;

