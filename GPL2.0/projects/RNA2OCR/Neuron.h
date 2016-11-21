#pragma once
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

struct Connection
{
	double weight;
	double deltaWeight;
};

class Neuron;

typedef vector<Neuron> Layer;

class Neuron
{
public:
	Neuron(int numOutputs, int index);
	void setOutputVal(double val) { output = val; }
	double getOutputVal(void) const { return output; }
	void feedForward(const Layer &prevLayer);
	void calcOutputGradients(double target);
	void calcHiddenGradients(const Layer &nextLayer);
	void updateInputWeights(Layer &prevLayer);
	static double txap;   
	unsigned int ID;

private:
	static int seed;
	static double transferFunction(double x);
	static double randomWeight(void);

	double output;
	vector<Connection> m_outputWeights;
	int index;
	double delta;
};

