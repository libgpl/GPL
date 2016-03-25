#include <gpl>

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	Timer tempo;

	tempo.restart(23, 59, 50);

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		//panel->debug("Terminou?", tempo.timeEnded());
		panel->debug("Tempo", tempo.getTime());

		//if (tempo.timeEnded())
		//{
		//	cout << tempo.timeEnded() << endl;
		//	tempo.restart(0,0,5);
		//}

		// BLOCO DE COMANDOS

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

