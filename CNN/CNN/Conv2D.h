#pragma once
#include <iostream>
#include<vector>
class Input2D;
class AveragePooling2D;
class MaxPooling2D;

using namespace std;
class Conv2D
{
	public:
		Conv2D(int num_filters, int kernel_size, Input2D* previous_layer, string activation_function);
		Conv2D(int num_filters, int kernel_size, AveragePooling2D *previous_layer, string activation_function);
		Conv2D(int num_filters, int kernel_size, MaxPooling2D *previous_layer, string activation_function);
		vector<int> getLayer_input_size();
		vector<int> getLayer_output_size();

	private:
		int kernel_size;
		int num_filters;
		string activation;
		string activation_function;
		Input2D *previous_input_layer;
		AveragePooling2D	*previous_average_pooling_layer;
		MaxPooling2D	*previous_max_pooling_layer;

		vector<int> filter_bank_size;
		vector<float> initial_weights;
		vector<vector<vector<int>>> layer_input_size;
		vector<vector<vector<int>>> layer_output_size;
		vector<vector<vector<vector<float>>>> trained_weights;
		vector<vector<vector<vector<int>>>> filter_bank_size;
		vector<int>	layer_input_size, layer_output_size;
};