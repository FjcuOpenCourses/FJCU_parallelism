#pragma once
#include <iostream>
#include<vector>
#include "Input2D.h"
using namespace std;
class Conv2D
{
	public:
		Conv2D(int num_filters, int kernel_size, Input2D previous_layer)//, activation_function)
		{
			/*
			num_filters: Number of filters in the convolution layer.
			kernel_size : Kernel size of the filter.
			previous_layer : A reference to the previous layer.
			activation_function = None : The name of the activation function to be used in the conv layer.If None,
								  then no activation function is applied besides the convolution operation.
								  The activation function can be applied by a separate layer.
			*/
			
			if (num_filters <= 0)
				std::cout << "Number of filters cannot be <= 0. Please pass a valid value to the 'num_filters' parameter.\n";
			// # Number of filters in the conv layer.
			this -> num_filters = num_filters;

			if (kernel_size <= 0)
				std::cout << "The kernel size cannot be <= 0. Please pass a valid value to the 'kernel_size' parameter.\n";
			// # Kernel size of each filter.
			this -> kernel_size = kernel_size;

			// # Validating the activation function
			if (activation_function == None)
				this -> activation = None;
			else if (activation_function == "relu")
				this -> activation = relu;
			else if (activation_function == "sigmoid")
				this -> activation = sigmoid;
			else if (activation_function == "softmax") :
				cout << "The softmax activation function cannot be used in a conv layer.\n";
			else
				cout << "The specified activation function " << activation_function << " is not among the supported activation functions " << supported_activation_functions << ".Please use one of the supported functions.\n";

			// # The activation function used in the current layer.
			this -> activation_function = activation_function;


			if (previous_layer == None)
				cout << "The previous layer cannot be of Type 'None'. Please pass a valid layer to the 'previous_layer' parameter.\n";
			// # A reference to the layer that preceeds the current layer in the network architecture.
			this -> previous_layer = previous_layer;

			// # A reference to the bank of filters.
			/*
			this -> filter_bank_size = (this -> num_filters,
				this -> kernel_size,
				this -> kernel_size,
				this -> previous_layer.layer_output_size[-1])*/


		}
		vector<vector<float>> conv(vector<vector<float>> input2D);
	private:
		int kernel_size;
		int num_filters;
		// activation
		// activation_function
		Input2D previous_layer;
		vector<int> filter_bank_size;
		vector<vector<vector<int>>> layer_input_size;
		vector<vector<vector<int>>> layer_output_size;
		vector<vector<vector<vector<float>>>> initial_weights;
		vector<vector<vector<vector<float>>>> trained_weights;
};