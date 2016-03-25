#include "../include/Music.hpp"
#include "../include/Window.hpp"


Music::Music(void)
{
}

Music::~Music(void)
{
}

void Music::load(std::string Filename)
{
	std::string File = "./assets/musics/" + Filename;
	if(!_music.openFromFile(File))
	{
		panel->debug("ERROR","Arquivo de música '"+Filename+"' não encontrado");
	}		
}

void Music::play(int volume, bool repeat)
{
	if(this->volume != volume) _music.setVolume((float)volume);
	if(this->repeat != repeat) _music.setLoop(repeat);
	_music.play();
}

void Music::pause()
{
	_music.pause();
}

void Music::stop()
{
	_music.stop();
}