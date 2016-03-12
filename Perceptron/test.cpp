/*
#include "Neuron.h"
#include "Perceptron.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#define NUM 4

int main() {

	int i = 0, j = 0;
	vector<Neuron> my_neurons(NUM);
	vector<double> input(NUM);
	vector<int> output(NUM);
	vector<int> true_output(NUM);
	for (i = 0; i < NUM; i++) {
		my_neurons[i].PostInitialization(NUM, 1);
		my_neurons[i].InitRandWeights(1);

	}
	Perceptron my_perceptron(my_neurons);
	
	input[0] = input[1] = input[3] = 0;
	input[2] = 1;
	cout << "Input vector:";
	for (i = 0; i < NUM; i++) {
		cout << input[i] << " ";
	}
	cout << endl;

	cout << "Calculated vector: ";
	output = my_perceptron.Calculate(input);
	for (i = 0; i < NUM; i++) {
		cout << output[i] << " ";
	}
	cout << endl;
	
	true_output[0] = 0;
	true_output[1] = true_output[2] = true_output[3] = 1;
	cout << "True vector: ";
	for (i = 0; i < NUM; i++) {
		cout << true_output[i] << " ";
	}
	cout << endl;
	cout << my_neurons[0].GetSynapses() << endl;
	for (i = 0; i < NUM; i++) {
		cout << "===========================" << endl;
		cout << "#" << i << endl;
		for (j = 0; j < NUM; j++) {
			cout << my_neurons[i].GetWeight(j) << endl;
		}
	}

	my_perceptron.Teach(input, true_output, 0.1);

	cout << "New output vector: ";
	output = my_perceptron.Calculate(input);
	for (i = 0; i < NUM; i++) {
		cout << output[i] << " ";
	}
	cout << endl;
}
*/