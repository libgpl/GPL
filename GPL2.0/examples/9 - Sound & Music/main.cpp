#include <gpl>
// * * * * * Créditos * * * * * * //
// Prof. MSC. Luan Carlos Nesi	  //
//  Leonardo Schmitt Teixeira	  //
// * * * * * * * * * * * * * * *  //

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
	
	// Declaração das variáveis de texto
	Text meuQueridoTexto;
	
	// Declaração das variáveis de som e música
	Sound tiro;
	Sound sound;
	Music musica;
	
	// Load dos textos
	meuQueridoTexto.load("calibri.ttf");

	// Load das músicas e dos sons
	tiro.load("Tiro.ogg");
	sound.load("Sound.ogg");

	musica.load("Music.ogg");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{		
		// BLOCO DE COMANDOS

		meuQueridoTexto.draw("Use as teclas direcionais!", 250, 370, 30);

		
		if (input->isDown(KEY::Right))
		{
			// Inicia o som com as configurações padrões
			tiro.play();
		}	
		else if (input->isDown(KEY::Left))
		{
			// Inicia o som com volume 20, sem repetição
			sound.play(20, false);
		}
		else if(input->isDown(KEY::Up))
		{
			// Inicia a música com volume 10, com repetição
			musica.play(10,true);
		}

		else if (input->isDown(KEY::Down))
		{
			musica.pause();
		}

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

