#pragma once
#include <string>
#include <iostream>
using namespace std;

#include <SFML/Audio.hpp>
#include "gplObj.h"

class musica : gplObj
{
private:
	sf::Music music;
	int volume;
	bool repetir;
public:

	musica(void);
	~musica(void);

	void carregar(string arquivo);
	void tocar(int volume = 10, bool repetir = false);
	void pausar();
	void parar();
};

