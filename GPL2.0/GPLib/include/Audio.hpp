#pragma once
#include "Object.hpp"

class Audio : public Object
{
protected:
	int volume;
	bool repeat;
public:
	Audio(void){}
	~Audio(void){}
	virtual void load(std::string Filename) = 0;
	virtual void play(int volume = 10, bool repeat = false) = 0;
	virtual void pause() = 0;
	virtual void stop() = 0;
};