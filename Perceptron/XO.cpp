#include "Neuron.h"
#include "bmp_to_array.h"
#include "Perceptron.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#define NUM_OF_NEURONS 1
#define PIC_SIZE 10

vector<double> FromRGBQuadToBoolArray(vector<RGBQuad> pixels);

int main() {

	int i = 0, j = 0;
	vector<Neuron>	XO_neurons(NUM_OF_NEURONS);
	vector<int>		output(NUM_OF_NEURONS);
	vector<double>	input_X(PIC_SIZE * PIC_SIZE);
	vector<double>	input_O(PIC_SIZE * PIC_SIZE);
	vector<int>		true_output_X(NUM_OF_NEURONS);
	vector<int>		true_output_O(NUM_OF_NEURONS);
	vector<RGBQuad>	pixels;

	true_output_X[0] = 1; 
	true_output_O[0] = 0;

	for (i = 0; i < NUM_OF_NEURONS; i++) {
		XO_neurons[i].PostInitialization(PIC_SIZE * PIC_SIZE, 1);
		//XO_neurons[i].InitRandWeights(1);
	}

	Perceptron XO_perceptron(XO_neurons);
	XO_perceptron.ReadWeightsFromFile("XO_weights.txt");
	ReadPixels("XO_test.bmp", pixels);
	output = XO_perceptron.Calculate(FromRGBQuadToBoolArray(pixels));

	if (output[0] == 1 ) cout << "It's X!" << endl;
	else cout << "It's O!" << endl;
	

	/*
	//input_X = FromRGBQuadToBoolArray(ReadPixels("Teach_X.bmp"));
	input_O = FromRGBQuadToBoolArray(ReadPixels("Teach_O.bmp"));

	//XO_perceptron.Teach(input_X, true_output_X, 0.05);
	XO_perceptron.Teach(input_O, true_output_O, 0.05);

	XO_perceptron.WriteWeightsInFile("XO_weights.txt");
	*/


/*	true_output[0] = 0;
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
*/

}

vector<double> FromRGBQuadToBoolArray(vector<RGBQuad> pixels) {

	int i = 0;
	int size_of_pixels = pixels.size();
	vector<double> input(size_of_pixels);

	for (i = 0; i < size_of_pixels; i++) {
		if (pixels[i].rgbBlue > 128 && pixels[i].rgbGreen > 128 && pixels[i].rgbRed > 128) {
			input[i] = 0;
		}
		else {
			input[i] = 1;
		}
	}
	return input;
}
