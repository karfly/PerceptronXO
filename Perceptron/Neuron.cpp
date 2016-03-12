#include "Neuron.h"


Neuron::Neuron() :
	synapses_(0),
	weights_(),
	threshold_(0)
{

}

Neuron::Neuron(size_t numb_of_synapses, double threshold) {

	PostInitialization(numb_of_synapses, threshold);
}

Neuron::Neuron(size_t numb_of_synapses) {

	PostInitialization(numb_of_synapses, 0);
}

Neuron::~Neuron() {

	weights_.~vector();
}

void Neuron::PostInitialization(size_t numb_of_synapses, double threshold) {

	synapses_	= numb_of_synapses;
	threshold_	= threshold;
	weights_.resize(numb_of_synapses);
}

Neuron::Neuron(const Neuron & that) {

	this->synapses_  = that.synapses_;
	this->threshold_ = that.threshold_;
	this->weights_	 = that.weights_;
}


void Neuron::InitRandWeights(double max_numb) {

	assert(max_numb > 0);

	size_t i = 0;

	srand((unsigned int)time(NULL));
	for (i = 0; i < synapses_; i++) {
		weights_[i] = 0 + double(rand()) / RAND_MAX * (max_numb - 0);
	}
}

double Neuron::Adder(const vector<double> & x) {

	assert(x.size() == synapses_);

	size_t i = 0;
	double sum = 0;

	for (i = 0; i < synapses_; i++) {
		sum += x[i] * weights_[i];
	}
	return sum;
}

void Neuron::ChangeWeights(const vector<double> & x, int delta, double t_speed) {

	assert(synapses_ == x.size());

	size_t i = 0;

	for (i = 0; i < synapses_; i++) {
		weights_[i] += x[i] * delta * t_speed;
	}
}

void Neuron::ChangeWeight(size_t i, double new_weight) {

	assert(i < synapses_);
	weights_[i] = new_weight;
}

void Neuron::SetSynapses(size_t synapses) {

	size_t i = 0;

	synapses_ = synapses;
	weights_.reserve(synapses);

	for (i = 0; i < synapses; i++) {
		weights_.push_back(0);
	}
}

void Neuron::SetThreshold(double threshold) {

	threshold_ = threshold;
}

bool Neuron::Activator(double x) {
	if (x >= threshold_) return true;
	else return false;
}

size_t Neuron::GetSynapses() {
	return synapses_;
}

double Neuron::GetWeight(size_t i) {

	assert(i < synapses_);
	return weights_[i];
}

double Neuron::GetThreshold() {

	return threshold_;
}