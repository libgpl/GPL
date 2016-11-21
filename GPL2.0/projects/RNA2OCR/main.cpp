#include "Network.h"

/*
Passos:
1) Aplicar o vetor de
xp = Xp11, Xp21, ... , Xpn)^T
2) Calcular os valores do NET para as unidades escondidas
3) Calculas as saídas (ativação) da camada escondida
4) Na camada de saída, calcular os valores do NET para as unidades de saída
5) Calcular a ativação da saída
6) Calcular os termos de erro para as unidades de saída
7) Calcular os termos de erro para as unidades escondidas
	delta_o = (desejado - obtido) * obtido * (1 - obtido)
8) Atualizar os pesos na camada de saída
	delta_o(t+1) = peso_o + txap * delta_o * saida_Nh
9) Atualizar os pesos na camada escondida
	peso_h(t+1) = peso_h(t) + txap * delta_h * entrada
Para cada amostra de treino:
	- Propaga
	- Adapta
Para todas as amostras de treino:
	Calcula o erro para cada amostra
	erro = erro + (desejado - obtido)²
Calcula o EMQ geral
	EMQ(epoca) = erro / nro_amostras
*/

void main()
{
	// Cria a janela
	Window janela(800, 600, "ANN 2 OCR", true, false);

	// Define o número de épocas
	int EPOCAS = 3000;

	// Cria a rede e carrega suas configurações
	Network rede("rede.txt");

	// Carrega a imagem do pixel
	Sprite pixel;
	pixel.load("0.png");

	Sprite screen;
	screen.load("screen.png");

	// Imagem do padrão de entrada
	Sprite entrada[6][5];
	string padraoEntrada = "000000000000000000000000000000";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			entrada[i][j].load("1.png");
		}
	}
	// Sprite do mouse
	Sprite mouse;
	mouse.load("mouse.png");

	// Variável de texto
	Text texto;

	// Botões
	Button stop("stop.png");
	Button run("run.png");
	Button pause("pause.png");
	Button detect("detect.png");

	texto.load("calibri.ttf");
	int epoca = 0;

	bool running = false;
	bool detecting = false;

	vector<double> results;
	vector<double> padraoDetectado;
	double colorFactor = 0.0;

	double error = 0.0;

	while (!input->isPressed(KEY::Escape))
	{
		// Atualiza o número de épocas
		rede.epochControl(EPOCAS);

		// Desenha os botões
		run.draw(340, 200);
		pause.draw(340, 250);
		stop.draw(340, 300);
		detect.draw(340, 350);

		// Comportamento dos botões
		if (run.onClick())
		{
			running = true;
		}
		else if (pause.onClick())
		{
			running = false;
		}
		else if (stop.onClick())
		{
			running = false;
			epoca = 0;
		}
		else if (detect.onClick())
		{
			running = false;
			detecting = true;
		}

		// Se estado for de treinamento da rede
		if (running)
		{
			// Executa a rede
			running = rede.run(EPOCAS, epoca, error);
			epoca++;
			colorFactor = (256 * 256 * 256) / rede.getResults(results);
		}

		// Define as imagens pré-carregadas dos padrões
		if (input->isDown(MOUSE::Right)) { padraoEntrada = "000000000000000000000000000000"; }
		else if (input->isDown(KEY::A)) { padraoEntrada = "011101000111111100011000110001"; }
		else if (input->isDown(KEY::B)) { padraoEntrada = "111101000111110100011000111110"; }
		else if (input->isDown(KEY::C)) { padraoEntrada = "011111000010000100001000001111"; }
		else if (input->isDown(KEY::D)) { padraoEntrada = "111101000110001100011000111110"; }
		else if (input->isDown(KEY::E)) { padraoEntrada = "111111000011110100001000011111"; }
		else if (input->isDown(KEY::F)) { padraoEntrada = "011111000011110100001000010000"; }
		else if (input->isDown(KEY::G)) { padraoEntrada = "011101000010110100011000101110"; }
		else if (input->isDown(KEY::H)) { padraoEntrada = "100011000111111100011000110001"; }
		else if (input->isDown(KEY::I)) { padraoEntrada = "111110010000100001000010011111"; }
		else if (input->isDown(KEY::J)) { padraoEntrada = "000010000100001100011000101110"; }

		// Verifica o padrão que o usuário desenhou
		screen.draw(40, 180,2,2);
		int cc = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (padraoEntrada.at(cc) == '0')
				{
					entrada[i][j].draw(j * 42 + 61, i * 42, 3, 3);
				}

				if (input->isPressed(MOUSE::Left) && mouse.collides(entrada[i][j]))
				{
					padraoEntrada.at(cc) = '1';
				}

				cc++;
			}
		}

		// Início do desenho dos padrões
		for (int p = 0; p < rede.entrada.size(); p++)
		{
			// Desenha o grid das amostras e valores
			gizmos->rectangle(p * 80, 0, 80, 100);
			gizmos->rectangle(p * 80, 100, 80, 20);
			gizmos->rectangle(p * 80, 120, 80, 20);

			// Desenha os caracteres de entrada
			int c = 0;
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (rede.entrada[p].at(c) == 1)
					{
						pixel.draw(j * 14 + p * 80 + 5, i * 14);
					}
					c++;
				}
			}
			if (epoca > 0)
			{
				int R = int(colorFactor * results[p]) % 256;
				int G = int((colorFactor * results[p]) / 256) % 256;
				int B = int(((colorFactor * results[p]) / 256) / 256) % 256;
				texto.draw(to_string(results[p]), 14 + p * 79, 100, 15, R, G, B);
			}
		}
		// Fim do desenho dos padrões

		// Se clicar no botão de detecção
		if (detecting && epoca > 0)
		{
			// Copia a string do padrão de entrada para um vetor
			vector<double> teste;
			for (int i = 0; i < padraoEntrada.size(); i++)
			{
				teste.push_back(padraoEntrada.at(i) - 48);
			}
			// Aplica o padrão na rede
			rede.feedForward(teste);
			rede.getResults(padraoDetectado);
			
			detecting = false;
		}

		// Verifica qual o padrão com o menor erro
		int maior = 0;
		for (int i = 0; i < padraoDetectado.size(); i++)
		{
			if (padraoDetectado[i] > padraoDetectado[maior]) maior = i;
		}

		// Imprime o erros da detecção
		for (int i = 0; i < padraoDetectado.size(); i++)
		{
			if (i == maior)
			{
				texto.draw(to_string(padraoDetectado[i]), 14 + i * 79,120, 15, 0, 255, 0);
			}
			else
			{
				texto.draw(to_string(padraoDetectado[i]), 14 + i * 79,120, 15, 255, 0, 0);
			}
		}

		// Desenha o mouse
		mouse.draw(input->getMouseX(), input->getMouseY());

		// Escreve a época e o erro do treinamento
		texto.draw("Epoch: " + to_string(epoca) + "|" + to_string(EPOCAS), 60,500, 20);
		texto.draw("ERROR: " + to_string(error), 530, 500, 20);

		texto.draw("Keys A to F \n\n\n Up \n Down \n Ctrl + Up \n Ctrl + Down \n Ctrl + Shift + Up \n Ctrl + Shift + Down \n Mouse Left \n Mouse Right", 500, 200,15);
		texto.draw("insert the input \npattern for detection \n\n increase epochs in 1\n decrease epochs in 1 \n increase epochs in 10 \n decrease epochs in 10 \n increase epochs in 100 \n decrease epochs in 100 \n draw pattern \n clear pattern", 630, 200, 15);

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

