#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "Base.h"
#include "Object.h"
using namespace std;

struct message
{
	string key;
	string value;
};


class Panel : public Object
{
public:
	Panel(void);
	~Panel(void);

	template <typename variable>
	void Debug(string key, variable value)
	{
		string tempVar;
		stringstream conv;
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
	int getMessagePollSize();
private:
	Panel(bool placebo){}
	Base *base;
	vector<message*> messagePoll;
	static Panel *single;
};