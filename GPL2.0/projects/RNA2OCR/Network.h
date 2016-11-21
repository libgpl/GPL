#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include "Neuron.h"
#include <gpl>

using namespace std;

class Network
{
public:
	Network(const string inputFile);
	~Network();

	void feedForward(const vector<double> &inputs);
	void backPropagation(const vector<double> &targets);
	double getResults(vector<double> &resultVals) const;

	double EMQ(const vector<double> &targets);

	bool run(int EPOCAS, int &epoca, double &error);

	vector<vector<double>> entrada;
	vector<vector<double>> saida;
	void epochControl(int &EPOCAS);
private:
	ifstream fileRead;
	ofstream fileOut;



	ifstream inputFile;
	void getTopology();
	void InputFile();

	vector<int> topology;
	vector<Layer> layers;
	double m_error;

};

