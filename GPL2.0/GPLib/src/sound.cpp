#include "../include/Sound.hpp"
#include "../include/Window.hpp"

/// <summary>
/// Cria um arquivo de Sound <see cref="Sound"/>.
/// </summary>
Sound::Sound(void)
{
	panel = new Panel();
}


Sound::~Sound(void)
{
}

/// <summary>
/// Carrega um arquivo de Sound (ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam, w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64)
/// </summary>
/// <param name="arquivo">Caminho do arquivo de Sound a ser carregado</param>
void Sound::load(std::string filename)
{
	std::string file = "./assets/sounds/" + filename;
	if(!buffer.loadFromFile(file))
	{
		panel->Debug("ERRO","Arquivo de som '"+filename+"' não encontrado");
	}	

	_sound.setBuffer(buffer);
}

/// <summary>
/// Começa a tocar o Sound.
/// </summary>
/// <param name="volume">Define o volume do Sound.</param>
/// <param name="repetir">Define se o Sound deve repetir</param>
void Sound::play(int volume, bool repeat)
{
	if(this->volume != volume) _sound.setVolume((float)volume);
	if(this->repeat != repeat) _sound.setLoop((float)repeat);
	_sound.play();
}

/// <summary>
/// Pausa o Sound.
/// </summary>
void Sound::pause()
{
	_sound.pause();
}


/// <summary>
/// Para de tocar o Sound.
/// </summary>
void Sound::stop()
{
	_sound.stop();
}