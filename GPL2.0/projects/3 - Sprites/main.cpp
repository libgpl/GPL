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
	minhaQueridaImagem.load("backgroudEx2.jpg");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	
	float angulo = 0;
	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS
		angulo = angle(400,300, input->getMouseX(), input->getMouseY());
		panel->debug("Angulo", angulo);
		
		gizmos->line(400, 300, distance(400, 300, input->getMouseX(), input->getMouseY()),1,255,0,0,255,angulo);
		gizmos->line2(400, 300, input->getMouseX(), input->getMouseY());
		//if (input->isDown(KEY::Up))
		//{
		//	angulo += 5;
		//}

		//if (input->isDown(KEY::Down))
		//{
		//	angulo -= 5;
		//}
		//gizmos->line2(10, 10, 100, 100, 255,0,0,255);
		// Desenha a sprite
		// x = 0			y = 600
		// scaleX = 1.5		scaleY = 1.5
		//minhaQueridaImagem.draw(330, 400, 1.5,1.5);

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

