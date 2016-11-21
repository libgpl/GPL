#include <gpl>

//#include <MyGame.h>
#include <iostream>
using namespace std;

#ifndef PI
#define PI 3.14159265358979
#endif

//float EaseInCubic(float t, float d, float b, float c)
//{
//	if (b == c) return b;
//	c = c - b;
//	return c*t*t*t + b;
//}
//
//float EaseOutElastic(float t, float b, float c, float d)
//{
//	if (b == c) return b;
//	c = c - b;
//
//	float s = 1.70158f;
//	float p = 0.0f;
//	float a = c;
//
//	if (t == 0)
//		return b;
//	if ((t /= d) == 1)
//		return b + c;
//	if (!p)
//		p = d*.3;
//
//	if (a < fabsf(c))
//	{
//		a = c;
//		s = p / 4.0f;
//	}
//	else
//	{
//		s = p / (2.0f * PI) * asin(c / a);
//	}
//
//	return a*pow(2, -10 * t) * sin((t*d - s)*(2.0f * PI) / p) + c + b;
//}
//
//
//float EaseInQuintic(float t, float d, float b, float c)
//{
//	if (b == c) return b;
//	c = c - b;
//	return c*(t /= d)*t*t*t*t + b;
//}
//
//float EaseOutCircular(float t, float b, float c, float d)
//{
//	if (b == c) return b;
//	c = c - b;
//	return c * sqrt(1 - (t = t / d - 1)*t) + b;
//}
//

//t
//d
//i->b
//desloc->c
//float uniEaseLinear(float t, float d, float i, float desloc)
//float EaseInLinear(float t, float b, float c, float d)


//		1 - t O tempo (valor entre 0 e 'duração')
//		3 - i b O valor inicial
//		4 - desloc c O deslocamento (fim - inicio)
//		2 - d A duração do easing;
//pos.x = uniEaseInBounce(tempo, duracaoMov, posInicio.x, destino.x - posInicio.x);
//pos.x = uniEaseInBounce(tempo, posInicio.x, destino.x - posInicio.x, duracaoMov);

struct Vector2D
{
	float x;
	float y;
};



Game
{
	Sprite teste;

	Vector2D pos;
	Vector2D posInicio;
	Vector2D destino;

	void Start()
	{
		teste.load("image.png");
		pos.x = 400;
		pos.y = 300;
		posInicio = pos;
		destino = pos;
	}

	void MinhaFunc()
	{
		panel->debug("W", pos.x);
		panel->debug("H", pos.y);
	}

	float tempo = 0;
	float duracaoMov;
	void Update()
	{
		if (input->isDown(MOUSE::Left))
		{
			// reseta pos inicial
			posInicio = pos;
			// nova posição de destino
			destino.x = input->getMouseX();
			destino.y = input->getMouseY();
			//	reseta o tempo
			tempo = 0;
			duracaoMov = 2.0f;
		}


		//if (pos.x != destino.x || pos.y != destino.y)
		{
			tempo+= 0.001;
			//if (tempo >= duracaoMov)
			//	tempo = duracaoMov;

			pos.x = EaseInCubic(tempo, duracaoMov, pos.x, destino.x);
			pos.y = EaseInQuintic(tempo, duracaoMov, pos.y, destino.y);
		}

		teste.draw(pos.x,pos.y);
		MinhaFunc();
		//if(input->isPressed(KEY::Up))
		//{
		//	x += inCircle(0.1);
		//	y += outCubic(0.1);
		//	//			app->resizeWindow(1024, 768);
		//	//Application->setWindowFullscreen();
		////	base->getInstance()->window->setSize(sf::Vector2u(1024, 768));
		////	//Quit();
		//}
		//if (input->isPressed(KEY::Down))
		//{
		//	x -= inCircle(0.1);
		//	y -= outCubic(0.1);
		//}
		//if (input->isDown(KEY::Right))
		//{
		//	Application->resizeWindow(300,400);
		//}
		//if (input->isDown(KEY::Left))
		//{
		//	Application->resizeWindow(800, 600);
		//}

		if (input->isDown(KEY::Escape)) Quit();
	}


	void Finish()
	{
		cout << "TESTE";
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
