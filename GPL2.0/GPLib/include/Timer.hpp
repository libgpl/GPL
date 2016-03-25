#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Timer
{
	sf::Clock relogio;
	sf::Time tempo;
	unsigned int hora;
	unsigned int minuto;
	unsigned int segundo;
	unsigned int time;
public:
	Timer();
	~Timer();

	//Retorna se o tempo terminou, esse método só serve se o tempo escolhido é do tipo cronômetro regressivo.  
	bool timeEnded();

	void restart(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0);
	
	const std::string getTime();
	const unsigned int getHour();
	const unsigned int getMinute();
	const unsigned int getSecond();

	void setSecond(unsigned int seconds);
	void setMinute(unsigned int minutes);
	void setHour(unsigned int hours);
};

