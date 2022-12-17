#pragma once
#include <iostream>
#include<vector>
#include "Input2D.h"
#include "AveragePooling2D.h"
#include "MaxPooling2D.h"

using namespace std;
class Conv2D
{
	public:
		Conv2D(int num_filters, int kernel_size, AveragePooling2D previous_layer, string activation_function);
		Conv2D(int num_filters, int kernel_size, Input2D previous_layer, string activation_function);
		Conv2D(int num_filters, int kernel_size, MaxPooling2D previous_layer, string activation_function);

		vector<vector<float>> conv(vector<vector<float>> input2D);
		vector<int> getLayer_input_size();
		vector<int> getLayer_output_size();

	private:
		vector<vector<vector<vector<float>>>> initial_weights;
		vector<vector<vector<vector<float>>>> trained_weights;
		Input2D previous_layer;
		int kernel_size;
		int num_filters;
		vector<vector<vector<vector<int>>>> filter_bank_size;
		vector<int> layer_input_size;
		vector<int> layer_output_size;
};