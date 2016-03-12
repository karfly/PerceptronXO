#ifndef PERCEPTRON_H
#define PERCEPTRON

#include "Neuron.h"

#include <iostream>
#include <fstream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

using std::ofstream;
using std::ifstream;

class Perceptron {
private:
	vector<Neuron> neurons_;

	/**
	* Constructor
	*
	* @brief	Basic constructor
	*/
public: Perceptron();

		/**
		* Constructor with initialization
		* @brief	Constructs neuron with initialization of weights_, synapses_, threshold_
		*
		* @param	numb_of_synapses	Number of sinapses
		*			threshold			Threshold for activation function
		*/
public: Perceptron(const vector<Neuron> & neurons);

		/**
		* Destructor
		*
		* @brief	Destructs the Perceptron
		*/
public: ~Perceptron();

		/**
		* Constructor of copying
		* @brief	Copies from one perceptron to another
		*
		* @param	that	From what perceptron to copy
		*/
public: Perceptron(const Perceptron & that);

		/**
		* GetSize
		* @brief	Returns the number of neurons in the Perceptron
		*
		* @return	Number of neurons in the Perceptron
		*/
public: int	GetSize();

		/**
		* WriteWeightsInFile (Maybe unsafe)
		* @brief	Writes weights of the neuron into the file
		*
		* @param	path	Pointer to the beginning of the string
		* @return	1		If file has been successfully opened
		*			0		If file hasn't been successfully opened
		*/
public: int WriteWeightsInFile(const char *path);						//************* Format of file *************
																		//|==========================================|
		/**																//|# 0										 |
		* ReadWeightsFromFile (Maybe unsafe)							//|0.705495									 |
		* @brief	Reads weights from file to the neuron				//|0.638281									 |
		*																//|-0.069598                                 |
		* @param	path	Pointer to the beginning of the string		//|											 |
		* @return	1		If file has been successfully opened		//|==========================================|
		*			0		If file hasn't been successfully opened		//|# 1										 |
		*																//|...										 |
		*/																
		
public: int ReadWeightsFromFile(const char *path);

		/**
		* Calculate
		* @brief	Calculates the output from the input signal
		*
		* @param	input	Input vector
		* @return			Output vector
		*/
public: vector<int> Calculate(vector<double> & input);


		/**
		* Teach
		* @brief	Teaches Perceptron using delta - rule
		*
		* @param	input			Input vector
		*			true_output		True output
					t_speed			Teaching speed
		*/
public: void Teach(vector<double> & input, vector<int> & true_output, double t_speed);

};

#endif