//#include "../include/music.h"
//#include "../include/gpl.h"
//
//
//music::music(void)
//{
//}
//
//music::~music(void)
//{
//}
//
//void music::load(string filename)
//{
//	string file = "./assets/musics/" + filename;
//	if(!_music.openFromFile(file))
//	{
//		debug("ERRO","Arquivo de música '"+filename+"' não encontrado");
//	}		
//}
//
//void music::play(int volume, bool repeat)
//{
//	if(this->volume != volume) _music.setVolume((float)volume);
//	if(this->repeat != repeat) _music.setLoop((float)repeat);
//	_music.play();
//}
//
//void music::pause()
//{
//	_music.pause();
//}
//
//void music::stop()
//{
//	_music.stop();
//}