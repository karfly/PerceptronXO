#include "Perceptron.h"

Perceptron::Perceptron() :
	neurons_()
{

}

Perceptron::Perceptron(const vector<Neuron> & neurons) :
	neurons_(neurons)
{
	
}

Perceptron::~Perceptron() {

	neurons_.~vector();
}

Perceptron::Perceptron(const Perceptron & that) {
	
	this->neurons_ = that.neurons_;
}

int Perceptron::GetSize() {

	return neurons_.size();
}

int Perceptron::WriteWeightsInFile(const char *path) {

	assert(path != NULL);														
																	
	std::ofstream File(path);											
	if (!File) return 0;												
																		
	int size = neurons_.size();											
	int temp_synapses = 0;												
	int i = 0, j = 0;													

	for (i = 0; i < size; i++) {
		File << "==========================================" << endl;
		File << "# "  << i << endl;
		
		temp_synapses = neurons_[i].GetSynapses();
		for (j = 0; j < temp_synapses; j++) {
			File << neurons_[i].GetWeight(j) << endl;
		}
	}
	File.close();
	return 1;
}

int Perceptron::ReadWeightsFromFile(const char *path){

	assert(path != NULL);

	std::ifstream File(path);
	if (!File) return 0;

	int size = neurons_.size();
	int temp_synapses = 0, temp_int = 0;
	double temp_double = 0;
	int i = 0, j = 0;
	

	while (File.get() != EOF) {
		File.ignore(100, '=');
		File.ignore(100, '\n');
		File.ignore(100, '#');

		File >> temp_int;
		temp_synapses = neurons_[temp_int].GetSynapses();

		for (i = 0; i < temp_synapses; i++) {
			File >> temp_double;
			neurons_[temp_int].ChangeWeight(i, temp_double);
		}

		File.ignore(100, '\n');
	}

	File.close();
	return 1;
}

vector<int> Perceptron::Calculate(vector<double> & input){

	assert(input.size() == neurons_[0].GetSynapses());

	int i = 0;
	int numb_of_neurons = neurons_.size();
	vector<int> output(numb_of_neurons);

	for (i = 0; i < numb_of_neurons; i++) {
		output[i] = neurons_[i].Activator(neurons_[i].Adder(input));
	}
	
	return output;
}

void Perceptron::Teach(vector<double> & input, vector<int> & true_output, double t_speed) {

	assert(input.size() == neurons_[0].GetSynapses());
	assert(true_output.size() == neurons_.size());

	int i = 0;
	bool is_teached = false;
	int numb_of_neurons = neurons_.size();
	vector<int> output(numb_of_neurons);
	vector<int> error(numb_of_neurons);

	output = this->Calculate(input);

	while (!is_teached) {
		for (i = 0; i < numb_of_neurons; i++){
			neurons_[i].ChangeWeights(input, true_output[i] - output[i], t_speed);
		}

		output = this->Calculate(input);
		if (output == true_output) is_teached = true;
		else					   is_teached = false;
	}
}