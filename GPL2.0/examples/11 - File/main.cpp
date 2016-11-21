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
	 
	// Declaração da variável texto
	Text minhaQueridaSenha;
	
	// Cria o arquivo configs.txt
 	File::Create("configs.txt");

	// Adiciona uma seção chamada 'senhas' ao arquivo 'configs.txt'
	File::AddSection("senhas", "configs.txt");

	// Adiciona um tag 'Level 1' com a chave 'Pa$$w0rd' na seção 'senhas' no arquivo 'configs.txt'
	File::SetValue("Level 1", "Pa$$w0rd", "senhas", "configs.txt");

	// Carregando a fonte que irá ser usada
	minhaQueridaSenha.load("calibri.ttf");

	//String para armazenar o conteúdo lido
	string valorLido = File::GetValue("Level 1", "senhas", "configs.txt");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{		
		// BLOCO DE COMANDOS
		
		// Draw do texto com o conteúdo lido
		minhaQueridaSenha.draw(valorLido, 100, 400,30);
		
		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

