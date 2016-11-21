#include "Neuron.h"

double Neuron::txap = 0.2; 
int Neuron::seed = time(0);
static int N_ID = 0;
double Neuron::randomWeight(void)
{
	seed+=1;
	srand(seed); 
	double rnd = rand() / double(RAND_MAX);
	return rnd;
}


void Neuron::updateInputWeights(Layer &prevLayer)
{
	// Passo 8) Atualizar os pesos na camada de saída
	// Passo 9) Atualizar os pesos na camada escondida

	for (int n = 0; n < prevLayer.size(); ++n) {
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[index].deltaWeight;

		double newDeltaWeight =
			oldDeltaWeight
			+ txap
			* delta
			* neuron.getOutputVal();

		neuron.m_outputWeights[index].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[index].weight = newDeltaWeight;
	}
}

void Neuron::calcHiddenGradients(const Layer &nextLayer)
{
	double sum = 0.0;

	// PASSO 7) Calcular os termos de erro para as unidades escondidas
	for (int n = 0; n < nextLayer.size() - 1; ++n) {
		sum += m_outputWeights[n].weight * nextLayer[n].delta;
	}
	delta = output * (1 - output) * sum;
}

void Neuron::calcOutputGradients(double target)
{
	// PASSO 6) Calcular os termos de erro para as unidades de saída
	delta = (target - output)
				* output
				* (1 - output);
}

// Função Sigmóide
double Neuron::transferFunction(double x)
{
	return 1.0 / (1.0 + exp(-x));
}


void Neuron::feedForward(const Layer &prevLayer)
{
	double net = 0.0;

	// Efetua a soma das saídas das camadas anteriores (que são as entradas)
	// Inclui o bias da camada anterior.
	for (int n = 0; n < prevLayer.size(); ++n)
	{
		net += prevLayer[n].getOutputVal() *
			prevLayer[n].m_outputWeights[index].weight;
	}

	output = Neuron::transferFunction(net);
}

Neuron::Neuron(int numOutputs, int index)
{
	// Define o ID único do neurônio
	N_ID++;
	ID = N_ID;

	// Atribui para cada neurônio um peso aleatório
	for (int c = 0; c < numOutputs; ++c)
	{
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
	this->index = index;
}
