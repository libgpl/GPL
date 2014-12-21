#include <gpl.h>

void main()
{
	// Seção de carregamento de assets

	gplInit(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca

	while (!isKeyPressed(KEY::Escape))		// Loop principal do jogo
    {
		// Lógica do Jogo
		
		gplFlush();		// Atualiza a tela - última coisa a ser chamada dentro do loop
    }
}