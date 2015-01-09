#include "../include/Music.h"
#include "../include/gpl.h"


Music::Music(void)
{
}

Music::~Music(void)
{
}

void Music::load(string filename)
{
	string file = "./assets/musics/" + filename;
	if(!_music.openFromFile(file))
	{
		// TODO: arrumar isso
		//debug("ERRO","Arquivo de música '"+filename+"' não encontrado");
	}		
}

void Music::play(int volume, bool repeat)
{
	if(this->volume != volume) _music.setVolume((float)volume);
	if(this->repeat != repeat) _music.setLoop((float)repeat);
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