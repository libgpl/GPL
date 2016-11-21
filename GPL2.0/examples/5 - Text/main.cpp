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
	
	// Variável do texto
	Text meuQueridoTexto;
	
	// Carregamento do texto com a fonte desejada
	meuQueridoTexto.load("calibri.ttf");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS
		
		// Desenha o texto na tela
		// "O texto que você deseja desenhar"
		// x = 230		y = 320
		// Tamanho fonte = 20
		// Cor do texto: R =  255, G = 0, B = 0

		meuQueridoTexto.draw("Meu primeiro texto na GPL!", 230, 320, 30,255,0,0);
	
		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

