#pragma once
#include "ObjectGPL.hpp"

class Audio : public ObjectGPL
{
protected:
	int volume;
	bool repeat;
public:
	Audio(void){}
	~Audio(void){}
	virtual void load(std::string filename) = 0;
	virtual void play(int volume = 10, bool repeat = false) = 0;
	virtual void pause() = 0;
	virtual void stop() = 0;
};