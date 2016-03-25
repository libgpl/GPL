#include "../include/Base.hpp"

Base::Base(void) : version("2.1.30")
{
	defaultText = new Text();
	defaultText->load("..\\..\\..\\..\\GPLib\\resources\\calibri.ttf");
}

Base* Base::getInstance()
{
	if(!instance)
	{
		instance = new Base();
	}
	return instance;
}


Base::~Base(void)
{
	if(instance)
	{
		delete instance;
	}
}
void Base::setWindow(_Window* window)
{
	getInstance();
	instance->window = window;
}

_Window* Base::getWindow() const
{
	getInstance();
	if(instance->window == NULL)
	{
		return NULL;
	}
	return instance->window;
}

std::string Base::getVersion() const
{
	getInstance();
	return version;
}

Base *Base::instance = NULL;