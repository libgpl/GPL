#define _USE_MATH_DEFINES
#include <gpl>
#include <cmath>

// * * * * * Créditos * * * * * * //
// Prof. MSc. Luan Carlos Nesi	  //
// * * * * * * * * * * * * * * *  //

struct Shot
{
	float x;
	float y;
	//float angle;
	bool enable;
	Sprite image;
	Sound sound;

	float s;
	float c;
	float speed = 0.2;

	Shot() {
		enable = false;
		sound.load("shot.ogg");
		image.load("tiro.png");
	}

	void launch(int _x, int _y, float _angle)
	{
		enable = true;
		s = sin(2 * M_PI * ((_angle) / 360));
		c = cos(2 * M_PI * ((_angle) / 360));

		x = _x + c * 50;
		y = _y + s * 50;
		//angle = _angle;
		sound.play();
	}

	void draw()
	{
		if (enable)
		{
			x += c * speed;
			y += s * speed;
			image.draw(x, y, 1, 1, image.getResX() / 2, -image.getResY() / 2);

			if (x < 0 || x > 800 || y < 0 || y > 600)
			{
				enable = false;
			}
		}
	}
};

struct Turret
{
	Sprite image;
	float angulo;
	int x;
	int y;

	Shot shots[10];

	Turret(string filename, int qtd_x, int qtd_y)
	{
		image.loadSpriteSheet(filename, qtd_x, qtd_y);
	}

	void fire()
	{
		for (int i = 0; i < 10; i++)
		{
			if (!shots[i].enable)
			{
				shots[i].launch(x + 50, y - 40, -angulo);
				break;
			}
		}
	}

	void setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void draw(int frame)
	{
		image.setFrame(frame);
		image.draw(x, y);
	}

	void update()
	{
		float deltaX = x - input->getMouseX();
		float deltaY = y - input->getMouseY();
		angulo = atan(deltaX / deltaY) * (180 / M_PI);


		if (deltaY > 0)
		{
			angulo = angulo + 90;
		}
		else
		{
			angulo = angulo + 270;
		}

		int imagem = int(abs(angulo / 5.625) + 16) % 64;
		draw(imagem);

		// Desenha os tiros habilitados
		for (int i = 0; i < 10; i++)
		{
			if (shots[i].enable)
			{
				shots[i].draw();
			}
		}

	}
};


void main()
{
	// Cria a janela
	Window janela(800, 600, "Turret", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Variável da animação
	Turret torre1("torre.png", 8, 8);
	torre1.setPosition(50, 355);

	Turret torre2("torre.png", 8, 8);
	torre2.setPosition(650, 355);

	Sprite fundo;
	fundo.load("fundo.png");

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		fundo.draw(0, 0);
		torre1.update();
		torre2.update();

		if (input->isDown(MOUSE::Left))
		{
			torre1.fire();
			torre2.fire();
		}

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}