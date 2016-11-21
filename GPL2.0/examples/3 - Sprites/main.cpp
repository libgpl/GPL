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
	
	//declaração da variável Sprite.
	Sprite minhaQueridaImagem;

	//load de uma imagem específica uma variável sprite.
	//arquivo = "backgroudEx.jpg"
	minhaQueridaImagem.load("backgroudEx.jpg");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS

		// Desenha a sprite
		// x = 0			y = 0
		// scaleX = 1.5		scaleY = 1.5
		minhaQueridaImagem.draw(0, 0, 1.5,1.5);

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

