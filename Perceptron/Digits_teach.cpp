#include "Neuron.h"
#include "bmp_to_array.h"
#include "Perceptron.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#define NUM_OF_NEURONS 10
#define PIC_SIZE 50

vector<double> FromRGBQuadToArray(vector<RGBQuad> pixels);
void TeachDigits(Perceptron & digits_perceptron, int digit);

vector<int>		true_output_0(NUM_OF_NEURONS);
vector<int>		true_output_1(NUM_OF_NEURONS);
vector<int>		true_output_2(NUM_OF_NEURONS);
vector<int>		true_output_3(NUM_OF_NEURONS);
vector<int>		true_output_4(NUM_OF_NEURONS);
vector<int>		true_output_5(NUM_OF_NEURONS);
vector<int>		true_output_6(NUM_OF_NEURONS);
vector<int>		true_output_7(NUM_OF_NEURONS);
vector<int>		true_output_8(NUM_OF_NEURONS);
vector<int>		true_output_9(NUM_OF_NEURONS);


int main() {

	int i = 0, j = 0;
	vector<Neuron>	Digits_neurons(NUM_OF_NEURONS);
	vector<int>		output(NUM_OF_NEURONS);
	vector<double>	input(PIC_SIZE * PIC_SIZE);

	/* Initialization of true outputs*/

	/* 0 */
	true_output_0[0] = 1;
	true_output_0[1] = true_output_0[2] = true_output_0[3] = true_output_0[4] = true_output_0[5] = true_output_0[6] = true_output_0[7] = true_output_0[8] = true_output_0[9] = 0;

	/* 1 */
	true_output_1[1] = 1;
	true_output_1[0] = true_output_1[2] = true_output_1[3] = true_output_1[4] = true_output_1[5] = true_output_1[6] = true_output_1[7] = true_output_1[8] = true_output_1[9] = 0;

	/* 2 */
	true_output_2[2] = 1;
	true_output_2[0] = true_output_2[1] = true_output_2[3] = true_output_2[4] = true_output_2[5] = true_output_2[6] = true_output_2[7] = true_output_2[8] = true_output_2[9] = 0;

	/* 3 */
	true_output_3[3] = 1;
	true_output_3[0] = true_output_3[1] = true_output_3[2] = true_output_3[4] = true_output_3[5] = true_output_3[6] = true_output_3[7] = true_output_3[8] = true_output_3[9] = 0;

	/* 4 */
	true_output_4[4] = 1;
	true_output_4[0] = true_output_4[1] = true_output_4[2] = true_output_4[3] = true_output_4[5] = true_output_4[6] = true_output_4[7] = true_output_4[8] = true_output_4[9] = 0;

	/* 5 */
	true_output_5[5] = 1;
	true_output_5[0] = true_output_5[1] = true_output_5[2] = true_output_5[3] = true_output_5[4] = true_output_5[6] = true_output_5[7] = true_output_5[8] = true_output_5[9] = 0;

	/* 6 */
	true_output_6[6] = 1;
	true_output_6[0] = true_output_6[1] = true_output_6[2] = true_output_6[3] = true_output_6[4] = true_output_6[5] = true_output_6[7] = true_output_6[8] = true_output_6[9] = 0;

	/* 7 */
	true_output_7[7] = 1;
	true_output_7[0] = true_output_7[1] = true_output_7[2] = true_output_7[3] = true_output_7[4] = true_output_7[5] = true_output_7[6] = true_output_7[8] = true_output_7[9] = 0;

	/* 8 */
	true_output_8[8] = 1;
	true_output_8[0] = true_output_8[1] = true_output_8[2] = true_output_8[3] = true_output_8[4] = true_output_8[5] = true_output_8[6] = true_output_8[7] = true_output_8[9] = 0;

	/* 9 */
	true_output_9[9] = 1;
	true_output_9[0] = true_output_9[1] = true_output_9[2] = true_output_9[3] = true_output_9[4] = true_output_9[5] = true_output_9[6] = true_output_9[7] = true_output_9[8] = 0;




	for (i = 0; i < NUM_OF_NEURONS; i++) {
		Digits_neurons[i].PostInitialization(PIC_SIZE * PIC_SIZE, 50);
		//Digits_neurons[i].InitRandWeights(50);
	}
	
	Perceptron Digits_perceptron(Digits_neurons);
	Digits_perceptron.ReadWeightsFromFile("Digits_weights.txt");

	output = Digits_perceptron.Calculate(FromRGBQuadToArray(ReadPixels("1.bmp")));
	for (i = 0; i < NUM_OF_NEURONS; i++) {
		cout << output[i] << " ";
	}
	cout << endl;

	TeachDigits(Digits_perceptron, 1);

	output = Digits_perceptron.Calculate(FromRGBQuadToArray(ReadPixels("1.bmp")));
	for (i = 0; i < NUM_OF_NEURONS; i++) {
		cout << output[i] << " ";
	}
	cout << endl;

	Digits_perceptron.WriteWeightsInFile("Digits_weights.txt");


}

vector<double> FromRGBQuadToArray(vector<RGBQuad> pixels) {

	int i = 0;
	int size_of_pixels = pixels.size();
	vector<double> input(size_of_pixels);

	for (i = 0; i < size_of_pixels; i++) {
		if (pixels[i].rgbBlue > 128 && pixels[i].rgbGreen > 128 && pixels[i].rgbRed > 128) {
			input[i] = -1;
		}
		else {
			input[i] = 1;
		}
	}
	return input;
}

void TeachDigits(Perceptron & digits_perceptron, int digit) {
	vector<int>	output(digits_perceptron.GetSize());

	switch (digit) {
	case 0:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("0.bmp")), true_output_0, 0.01);
		break;

	case 1:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("1.bmp")), true_output_1, 0.01);
		break;

	case 2:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("2.bmp")), true_output_2, 0.01);
		break;

	case 3:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("3.bmp")), true_output_3, 0.01);
		break;

	case 4:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("4.bmp")), true_output_4, 0.01);
		break;

	case 5:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("5.bmp")), true_output_5, 0.01);
		break;

	case 6:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("6.bmp")), true_output_6, 0.01);
		break;

	case 7:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("7.bmp")), true_output_7, 0.01);
		break;

	case 8:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("8.bmp")), true_output_8, 0.01);
		break;

	case 9:
		digits_perceptron.Teach(FromRGBQuadToArray(ReadPixels("9.bmp")), true_output_9, 0.01);
		break;

	default:
		break;
	}

}