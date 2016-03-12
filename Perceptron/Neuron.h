#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
#include <assert.h>


/* For random numbers */
#include <cstdlib>
#include <ctime>
/*====================*/

using std::vector;
using std::cout;
using std::endl;

#define POISON 0xDEAD

class Neuron {
private:

	size_t synapses_;
	vector<double> weights_;
	double threshold_;

		/**
		* Constructor
		*
		* @brief	Basic constructor
		*/
public: Neuron();

		/**
		* Constructor with initialization
		* @brief	Constructs neuron with initialization of weights_, synapses_, threshold_
		*
		* @param	numb_of_synapses	Number of sinapses
		*			threshold			Threshold for activation function
		*/
public: Neuron(size_t numb_of_synapses, double threshold);

		/**
		* Constructor with initialization of only weights_ and synapses_
		* @brief	Constructs neuron with initialization of weights_, synapses_
		*
		* @param	numb_of_synapses	Number of sinapses
		*/
public: Neuron(size_t numb_of_synapses);

		/**
		* Destructor
		*
		* @brief Destructs the neuron
		*
		*/
public: ~Neuron();


		/**
		* PostInitialization
		* @brief	Sets sinapses_ and threshold
		*
		* @param	numb_of_synapses	Number of synapses
		*			threshold			The value of threshold
		*/

public: void PostInitialization(size_t numb_of_synapses, double threshold);

		/**
		* Constructor of copying
		* @brief	Copies from one neuron to another
		*
		* @param	that	From what neuron to copy
		*/
public: Neuron(const Neuron & that);

		/**
		* InitRandWeights
		* @brief	Initializes weights with random numbers from 0 to max_numb+1
		*
		* @param	max_numb	Biggest random number
		*/
public:	void InitRandWeights(double max_numb);

		/**
		* Adder 
		* @brief	Calculates a weighted sum of the neuron
		*
		* @param	x       Input vector
		* @return			Weighted sum
		*/
public: double Adder(const vector<double> & x);

		/**
		* ChangeWeights 
		* @brief	Changes weights during teaching
		*
		* @param	x			Input vector
		*			delta		Difference between got output signal and true output signal
		*			t_speed		Speed of teaching
		*/
public:	void ChangeWeights(const vector<double> & x, int delta, double t_speed);

		/**
		* ChangeWeight
		* @brief	Changes weights_[i]
		*
		* @param	i				Index of the weight
		*			new_weight		New weight	
		*/

public:	void ChangeWeight(size_t i, double new_weight);

		/**
		* SetSynapses
		* @brief	Sets the synapses_
		*
		* @param	synapses	Number of synapses
		*/
public: void SetSynapses(size_t synapses);

		/**
		* SetThreshold 
		* @brief	Sets a new threshold  of activation function
		*
		* @param	level	New level
		*/


public: void SetThreshold(double threshold);

		/**
		* Activator 
		* @brief	A threshold function
		*
		* @param	x			The weighted sum of neuron
		* @return	1(true)		If the threshold is overcome
		* 			0(false)	If the threshold isn't overcome
		*/
public: bool Activator(double x);

		/**
		* GetSynapses
		* @brief	Returns synapses_
		*
		* @return	Number of synapses
		*/
public:	size_t GetSynapses();


		/**
		* GetWeight
		* @brief	Returns weights_[i]
		*
		* @param	i			Index of required weight
		* @return				Required weight
					0xDEAD		In case if there is no such index
		*/
public: double GetWeight(size_t i);

		/**
		* GetThreshold
		* @brief	Returns threhold_
		*
		* @return	Level of activation function (threhold_)

		*/
public: double GetThreshold();

};

#endif