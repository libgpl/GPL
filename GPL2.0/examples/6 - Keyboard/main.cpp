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
	
	//Variáveis dos textos
	Text meuQueridoTexto;
	
	//Carregamento do texto com a fonte desejada
	meuQueridoTexto.load("calibri.ttf");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		meuQueridoTexto.draw("Use as teclas direcionais!", 250, 520, 30);
		
		//Blocos de ifs que checam quais botões estão sendo apertados
		//Tipos de detecção: IsPressed, IsUp,IsDown
		//KEY::A tecla que desejas verificar

		if (input->isPressed(KEY::Left))
		{
			meuQueridoTexto.draw("ESQUERDA!", 350, 320, 30, 255, 0, 0);
		}
		else if (input->isPressed(KEY::Right))
		{
			meuQueridoTexto.draw("DIREITA!", 350, 320, 30, 255, 0, 0);
		}
		else if (input->isPressed(KEY::Up))
		{
			meuQueridoTexto.draw("ACIMA!", 350, 320, 30, 255, 0, 0);
		}
		else if (input->isPressed(KEY::Down))
		{
			meuQueridoTexto.draw("ABAIXO!", 350, 320, 30, 255, 0, 0);
		}

		// BLOCO DE COMANDOS

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

