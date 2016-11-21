#include <MyGame.hpp>

Game
{
	// Enumerador que define os estados de jogo
	enum GAME_STATE {MENU, GAME, OPTIONS, CREDITS, EXIT_GAME, MENU_INGAME};

	// Variável que armazena o estado atual do jogo
	GAME_STATE currentState;

	// Variável que armazena o estado anterior do jogo
	GAME_STATE previousState;

	// Cria as variáveis dos botoes do menu inicial
	Button newGame;
	Button options;
	Button credits;
	Button exit;

	Button back;

	Text texto;

	void Start()
	{
		// Carrega a fonte
		texto.load("Calibri.ttf");

		// Define o estao inical do jogo
		currentState = MENU;

		// Carrega os botões do menu inicial
		newGame = Button("new_game.png");
		options = Button("options.png");
		credits = Button("credits.png");
		exit	= Button("exit.png");

		back = Button("back.png");

	}

	void Menu()
	{
		texto.draw("MENU", 10, 550, 30);

		// Desenha os botoes do menu inicial
		newGame.draw(300, 400);
		options.draw(300, 325);
		credits.draw(300, 250);
		exit.draw(300, 175);

		// Ao pressionar o botão 'newGame'
		if(newGame.onClick())
		{
			// Define o estado atual como GAME
			currentState = GAME;
		}
		// Ao pressionar o botão 'options'
		else if(options.onClick())
		{
			previousState = currentState;
			// Define o estado atual como OPTIONS
			currentState = OPTIONS;
		}
		// Ao pressionar o botão 'credits'
		else if (credits.onClick())
		{
			// Define o estado atual como CREDITS
			currentState = CREDITS;
		}
		// Ao pressionar o botão 'exit'
		else if (exit.onClick())
		{
			// Define o estado atual como EXIT_GAME
			currentState = EXIT_GAME;
		}
	}

	void NewGame()
	{
		texto.draw("GAME", 10, 550, 30);

		// Ao pressionar o botão ESC
		if (input->isUp(KEY::Escape))
		{
			// Define o estado atual como MENU_INGAME
			currentState = MENU_INGAME;
		}
	}

	void Options()
	{
		texto.draw("OPTIONS", 10, 550, 30);

		// Desenha o botão 'back'
		back.draw(600, 100);

		// Ao pressionar o botão 'back'
		if (back.onClick())
		{
			// Define o estado atual como o estado anterior
			currentState = previousState;
		}
	}

	void Credits()
	{
		texto.draw("CREDITS", 345, 500, 30);
		texto.draw("Made by Prof. MSc. Luan Nesi with GPL 3.0", 140, 400, 30);
		texto.draw("Contact: luannesi@gmail.com", 220, 350, 30);

		// Desenha o botão de 'back'
		back.draw(600, 100);

		// Ao pressionar o botão 'back' ou pressionar ESC
		if (back.onClick() || input->isUp(KEY::Escape))
		{
			// Define o estado atual como MENU
			currentState = MENU;
		}
	}
	
	void MenuInGame()
	{
		texto.draw("MENU IN GAME", 10, 550, 30);

		// Desenha os botões do menu inicial
		options.draw(300, 400);
		exit.draw(300, 325);
		back.draw(300, 250);

		// Ao pressionar o botão 'exi'
		if (exit.onClick())
		{
			// Define o estado atual como MENU
			currentState = MENU;
		}
		
		// Ao pressionar o botão 'options'
		if(options.onClick())
		{
			// Armazena o estado atual
			previousState = currentState;

			// Define o estado atual como OPTIONS
			currentState = OPTIONS;
		}

		// Ao pressionar o botão 'back' ou ESC
		if (back.onClick() || input->isUp(KEY::Escape))
		{
			// Define o estado atual como GAME
			currentState = GAME;
		}
	}

	void Update()
	{
		// De acordo com cada estado uma nova função é chamada
		switch (currentState)
		{
		case MENU:
			Menu();
			break;
		case GAME:
			NewGame();
			break;
		case OPTIONS:
			Options();
			break;
		case CREDITS:
			Credits();
			break;
		case MENU_INGAME:
			MenuInGame();
			break;
		case EXIT_GAME:
			// A função 'Quit' finaliza a aplicação
			Quit();
			break;
		}
	}

	void Finish()
	{
	}
};
