#pragma once
#include <string>
#include <iostream>
using namespace std;

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "gplObj.h"

class som : gplObj
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	int volume;
	bool repetir;
public:

	som(void);
	~som(void);

	void carregar(string arquivo);
	void tocar(int volume = 10, bool repetir = false);
	void pausar();
	void parar();
};

