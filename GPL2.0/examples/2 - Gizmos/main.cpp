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

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS

		// x = 100	 y = 400	 raio = 50		espessura = 5
		// R = 255	 G = 0		 B = 0			A = 255
		gizmos->circle(100, 400, 50, 5, 255, 0, 0, 255);

		// x = 300		y = 400		comprimento = 50	espessura = 5
		// R = 0		G = 255		B = 0	A = 255		ângulo = 45
		gizmos->line(300, 400, 50, 1, 0, 255, 0, 255, 45);

		// x = 400		y = 400		R = 0		
		// G = 0		B = 255		A = 255
		gizmos->pixel(400, 400, 0, 0, 255, 255);

		// x = 500		y = 400		largura = 50	altura = 100	borda = 2
		// R = 255		G = 255		B = 0			A = 255			ângulo = 30
		gizmos->rectangle(500, 400, 50, 100, 2, 255, 255, 0, 255, 30);

		// Largura = 60	Altura = 60
		// R = 255			G = 255		B = 255			A = 255 (Padrões)
		gizmos->grid(60, 60);

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

