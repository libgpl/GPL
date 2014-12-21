//#include "../include/sound.h"
//#include "../include/gpl.h"
//
///// <summary>
///// Cria um arquivo de sound <see cref="sound"/>.
///// </summary>
//sound::sound(void)
//{
//}
//
//
//sound::~sound(void)
//{
//}
//
///// <summary>
///// Carrega um arquivo de sound (ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam, w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64)
///// </summary>
///// <param name="arquivo">Caminho do arquivo de sound a ser carregado</param>
//void sound::load(string filename)
//{
//	string file = "./assets/sounds/" + filename;
//	if(!buffer.loadFromFile(file))
//	{
//		debug("ERRO","Arquivo de som '"+filename+"' não encontrado");
//	}	
//
//	_sound.setBuffer(buffer);
//}
//
///// <summary>
///// Começa a tocar o sound.
///// </summary>
///// <param name="volume">Define o volume do sound.</param>
///// <param name="repetir">Define se o sound deve repetir</param>
//void sound::play(int volume, bool repeat)
//{
//	if(this->volume != volume) _sound.setVolume((float)volume);
//	if(this->repeat != repeat) _sound.setLoop((float)repeat);
//	_sound.play();
//}
//
///// <summary>
///// Pausa o sound.
///// </summary>
//void sound::pause()
//{
//	_sound.pause();
//}
//
//
///// <summary>
///// Para de tocar o sound.
///// </summary>
//void sound::stop()
//{
//	_sound.stop();
//}