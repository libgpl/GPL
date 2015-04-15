#include "gpl.hpp"

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// Seção de carregamento dos assets



	// LOOP PRINCIPAL DO JOGO
	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
    {

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
    }
}