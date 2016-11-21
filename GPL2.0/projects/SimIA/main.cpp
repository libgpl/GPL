#include "MyAI.h"

Game
{
	void Start()
	{
		SimIA(80, 60, 500, 1, "seed");
		registerBase(MyAI);
	}

	void Update()
	{
		exec();
	}


	void Finish()
	{
	}
};
