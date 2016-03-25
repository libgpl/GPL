#include "gpl.hpp"

enum CENA {MENU, JOGO, CREDITOS, SAIR, MENU_IN_GAME};

void main()
{
	Window janela(800,600, "Menu", false,false);
	Text text;
	text.load("calibri.ttf");
	while (!input->isPressed(KEY::Escape))
	{
		if (input->isPressed(JOYSTICK::L1, PLAYER_1)) text.draw("L1", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::R1, PLAYER_1)) text.draw("R1", 400, 300, 50);
		
		else if (input->isPressed(JOYSTICK::L2, PLAYER_1)) text.draw("L2", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::R2, PLAYER_1)) text.draw("R2", 400, 300, 50);

		else if (input->isPressed(JOYSTICK::SELECT, PLAYER_1)) text.draw("SELECT", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::START, PLAYER_1)) text.draw("START", 400, 300, 50);

		else if (input->isPressed(JOYSTICK::UP, PLAYER_1)) text.draw("UP", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::DOWN, PLAYER_1)) text.draw("DOWN", 400, 300, 50);

		else if (input->isPressed(JOYSTICK::LEFT, PLAYER_1)) text.draw("LEFT", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::RIGHT, PLAYER_1)) text.draw("RIGHT", 400, 300, 50);

		else if (input->isPressed(JOYSTICK::RIGHT_UP, PLAYER_1)) text.draw("RIGHT UP", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::RIGHT_DOWN, PLAYER_1)) text.draw("RIGHT DOWN", 400, 300, 50);

		else if (input->isPressed(JOYSTICK::RIGHT_LEFT, PLAYER_1)) text.draw("RIGHT LEFT", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::RIGHT_RIGHT, PLAYER_1)) text.draw("RIGHT RIGHT", 400, 300, 50);

		else if (input->isPressed(JOYSTICK::LEFT_STICK, PLAYER_1)) text.draw("LEFT STICK", 400, 300, 50);
		else if (input->isPressed(JOYSTICK::RIGHT_STICK, PLAYER_1)) text.draw("RIGHT STICK", 400, 300, 50);

		janela.flush();
	}
}