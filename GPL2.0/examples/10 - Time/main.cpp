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
	Sprite animacaoTimer;
	Sprite animacao;
	Timer tempo;	
	
	// Load das sprites sheets diferentes
	animacaoTimer.loadSpriteSheet("explosao.png", 5, 2);
	animacao.loadSpriteSheet("explosao.png", 5, 2);

	// Setando a velocidade das animações
	animacaoTimer.setSpeed(110);
	animacao.setSpeed(110);

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS
		
		// Para só começar a animação caso o espaço seja apertado depois do término da mesma
		if (input->isDown(KEY::Space) && animacaoTimer.getFrame() == 0)
		{
			// Reinicia o timer em horas, minutos e segundos
			tempo.restart(0, 0, 10);
		}
		//panel->debug("Tempo", (int)tempo.getSecond());
		// Se o tempo do timer não tiver terminado, desenhar
		if (!tempo.timeEnded())
		{
			animacaoTimer.draw(500, 300);
		}
		
		// Resetar para o frame 0, caso o tempo tenha acabado
		else
		{
			animacaoTimer.setFrame(0);
		}
		// Desenhando uma animação normal sem timer
		animacao.draw(100, 300);
		
		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

