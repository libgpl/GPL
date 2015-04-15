#pragma once
#include <string>

#include <vector>
#include "Object.hpp"

#define panel Panel::getInstance()


class Panel : public Object
{
public:
	~Panel(void);
	
	void debug(std::string key, std::string value);
	void debug(std::string key, bool value);
	void debug(std::string key, int value);
	void debug(std::string key, double value);
	void debug(std::string key, float value);
	void debug(std::string key, char value);

	void Draw();
	int getMessagePollSize() const;

	static Panel* getInstance();

private:
	Panel(void);

	struct message
	{
		std::string key;
		std::string value;
	};

	static Panel* instance;


	//Base* base;
	std::vector<message*> messagePoll;
};