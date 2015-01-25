#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "Object.hpp"

#define panel Panel::getInstance()


class Panel : public Object
{
public:
	~Panel(void);

	template <typename variable>
	void Debug(std::string key, variable value)
	{
		std::string tempVar;
		std::stringstream conv;
		conv << value;
		conv >> tempVar;

		message* deb = NULL;
		message* temp = NULL;
		for(unsigned int i = 0; i < messagePoll.size(); i++)
		{
			temp = messagePoll[i];
			if(temp->key == key && temp->key != "ERROR") deb = temp;
		}
		if(deb == NULL)
		{
			deb = new message;
			deb->key = key;
			deb->value = tempVar;
			messagePoll.push_back(deb);
		}
		else
		{
			deb->value = tempVar;
		}
	}

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