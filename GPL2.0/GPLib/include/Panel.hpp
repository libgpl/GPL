#pragma once
#include <string>

#include <vector>
#include "Object.hpp"

#define panel Panel::getInstance()


class Panel : public Object
{
public:
	~Panel(void);
	
	void Debug(std::string key, std::string value);
	void Debug(std::string key, bool value);
	void Debug(std::string key, int value);
	void Debug(std::string key, double value);
	void Debug(std::string key, float value);
	void Debug(std::string key, char value);

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