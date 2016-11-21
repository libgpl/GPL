//#include <gpl>
#include <MyGame.hpp>

Game
{
	Sprite a;
	void Start()
	{
		a.load("ascasca");
	}
	void Update()
	{
		a.draw(100, 100);
	}


	void Finish()
	{
	}
};



//void main()
//{
//	// Cria a janela
//	Window janela(800, 600, "Minha Janela", true, false);
//
//	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
//
//	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
//
//	// Enquanto a tecla 'ESC' não for pressionada
//	while (!input->isPressed(KEY::Escape))
//	{
//		// BLOCO DE COMANDOS
//
//		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
//		janela.flush();
//	}
//}
//
