#pragma once
#include <iostream>
#include<vector>

class Input2D;
class AveragePooling2D;
class MaxPooling2D;
class BaseLayer;

using namespace std;
class Conv2D:public BaseLayer
{
	public:
		Conv2D(int num_filters, int kernel_size, Input2D* previous_layer, string activation_function);
		Conv2D(int num_filters, int kernel_size, AveragePooling2D *previous_layer, string activation_function);
		Conv2D(int num_filters, int kernel_size, MaxPooling2D *previous_layer, string activation_function);
		vector<vector<vector<float>>> conv_(Input2D input2D);
		void conv(Input2D input2D);
		vector<int> getLayer_input_size();
		vector<int> getLayer_output_size();
	private:
		int kernel_size;
		int num_filters;
		ActivtionFunction activation;
		string activation_function;

		vector<int>	layer_input_size, layer_output_size, filter_bank_size;
		vector<vector<vector<vector<float>>>> initial_weights, trained_weights;
};