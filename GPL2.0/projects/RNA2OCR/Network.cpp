#include "Network.h"
#include <iostream>
#include <iomanip>
using namespace std;

double Network::getResults(vector<double> &resultVals) const
{
	double sum = 0.0;
	resultVals.clear();

	for (int n = 0; n < layers.back().size() - 1; ++n)
	{
		resultVals.push_back(layers.back()[n].getOutputVal());
		sum += resultVals.back();
	}
	return sum;
}

double Network::EMQ(const vector<double> &targets)
{
	Layer &outputLayer = layers.back();
	// Calcula o erro de uma entrada
	for (int n = 0; n < outputLayer.size() - 1; ++n)
	{
		m_error += pow(targets[n] - outputLayer[n].getOutputVal(), 2);
	}
	return m_error;
}


void Network::backPropagation(const vector<double> &targets)
{
	Layer &outputLayer = layers.back();

	// PASSO 6 - Calcula o gradiente da saída
	for (int n = 0; n < outputLayer.size() - 1; ++n)
	{
		outputLayer[n].calcOutputGradients(targets[n]);
	}

	// PASSO 7 - Calcula os gradientes das camadas ocultas
	for (int layerNum = layers.size() - 2; layerNum > 0; --layerNum)
	{
		Layer &hiddenLayer = layers[layerNum];
		Layer &nextLayer = layers[layerNum + 1];

		for (int n = 0; n < hiddenLayer.size(); ++n) {
			hiddenLayer[n].calcHiddenGradients(nextLayer);
		}
	}

	// Atualiza os pesos das conexões para todas as camadas da saída até a primeira camada oculta
	for (int layerNum = layers.size() - 1; layerNum > 0; --layerNum)
	{
		Layer &layer = layers[layerNum];
		Layer &prevLayer = layers[layerNum - 1];

		for (int n = 0; n < layer.size() - 1; ++n)
		{
			layer[n].updateInputWeights(prevLayer);
		}
	}
}

void Network::feedForward(const vector<double> &inputs)
{
	assert(inputs.size() == layers[0].size() - 1);

	// Atribui os valores de entrada aos neurônios da entrada
	for (int i = 0; i < inputs.size(); ++i)
	{
		layers[0][i].setOutputVal(inputs[i]);
	}

	// propagação feedforward
	for (int layerNum = 1; layerNum < layers.size(); ++layerNum)
	{
		Layer &prevLayer = layers[layerNum - 1];
		for (int n = 0; n < layers[layerNum].size() - 1; ++n)
		{
			layers[layerNum][n].feedForward(prevLayer);
		}
	}
}

Network::Network(const string inputFile):m_error(0.0)
{
	// Abre o arquivo de config da rede
	this->inputFile.open(inputFile.c_str());

	// Lê a topologia da rede do arquivo 
	getTopology();

	// Lê o padrão entrada/treinamento e a saída esperada
	InputFile();
	
	int numLayers = topology.size();
	for (int layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		// Adiciona um nova camada vazia
		layers.push_back(Layer());
		int numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

		// Adiciona neurônios e o bias em cada camada 
		for (int neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
		{
			layers.back().push_back(Neuron(numOutputs, neuronNum));
			//cout << "Neuron:	" << layerNum << "-" << layers.back().back().ID << endl;
		}
		// Define o último neurônio da camada como bias (1.0)
		layers.back().back().setOutputVal(1.0);
	}

	// --------- Arquivo do gráfico - Inicio Parte 1 --------- 
	fileOut.open("grafico.html");

	fileRead.open("assets/base_grafico.html");
	string linha;

	for (int i = 0; i < 16; i++)
	{
		getline(fileRead, linha);
		fileOut << linha << endl;
	}
	// --------- Arquivo do gráfico - Fim Parte 1 --------- 

}

Network::~Network()
{
}


void Network::getTopology()
{
	string line;
	string label;

	getline(inputFile, line);
	stringstream ss(line);
	ss >> label;
	if (label.compare("network:") != 0) {
		abort();
	}

	while (!ss.eof())
	{
		int n;
		ss >> n;
		topology.push_back(n);
	}

	return;
}

void Network::InputFile()
{
	while (!inputFile.eof())
	{

		string line;
		getline(inputFile, line);
		stringstream ss(line);

		string label;
		ss >> label;
		if (label.compare("input:") == 0)
		{
			entrada.push_back(vector<double>());
			double oneValue;
			while (ss >> oneValue)
			{
				entrada.back().push_back(oneValue);
			}
		}
		else if (label.compare("output:") == 0)
		{
			saida.push_back(vector<double>());
			double oneValue;
			while (ss >> oneValue)
			{
				saida.back().push_back(oneValue);
			}
		}
	}
}

void showVectorVals(string label, vector<double> &v)
{
	cout << label << " ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}

	cout << endl;
}


bool Network::run(int EPOCAS, int &epoca, double &error)
{
	vector<double> resultVals;
	int trainingPass = 0;


	if(epoca < EPOCAS)
	{
		//double erro = 0.0;
		//cout << endl << "---------- Epoca " << epoca << " ----------"<< endl;
		vector<int> apresentacao;
		for (int amostra = 0; amostra < entrada.size(); amostra++)
		{
			feedForward(entrada[amostra]);
			backPropagation(saida[amostra]);
			EMQ(saida[amostra]);
		}
		double emq = this->m_error / entrada.size();
		this->m_error = 0.0;
		fileOut << "[" << epoca << ", " << std::setprecision(15) << emq << "]," << endl;
		error = emq;
	
		return true;
	}
	// --------- Arquivo do gráfico - Inicio Parte 2 --------- 
	string linha;
	for (int i = 0; i < 121; i++)
	{
		getline(fileRead, linha);
		fileOut << linha << endl;
	}
	// --------- Arquivo do gráfico - Fim Parte 2 --------- 

	cout << endl << "FIM" << endl;
	return false;
}

void Network::epochControl(int &EPOCAS)
{
	if (input->isUp(KEY::Up))
	{
		if (input->isPressed(KEY::LControl) || input->isPressed(KEY::RControl))
		{
			if (input->isPressed(KEY::LShift) || input->isPressed(KEY::RShift))
			{
				EPOCAS += 100;
			}
			else
			{
				EPOCAS += 10;
			}
		}
		else
		{
			EPOCAS++;
		}
	}
	else if (input->isUp(KEY::Down))
	{
		if (input->isPressed(KEY::LControl) || input->isPressed(KEY::RControl))
		{
			if (input->isPressed(KEY::LShift) || input->isPressed(KEY::RShift))
			{
				EPOCAS -= 100;
			}
			else
			{
				EPOCAS -= 10;
			}
		}
		else
		{
			EPOCAS--;
		}
	}
	if (EPOCAS < 0) EPOCAS = 0;
}
