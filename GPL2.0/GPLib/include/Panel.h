#pragma once
#include <string>
#include <vector>
#include "Base.h"
using namespace std;

struct message
{
	string key;
	string value;
};


class Panel : public Base
{
public:
	Panel(void);
	~Panel(void);

	template <typename variable>
	void Debug(string key, variable value);
	void Draw();
	int getMessagePollSize();
private:
	vector<message*> messagePoll;
};