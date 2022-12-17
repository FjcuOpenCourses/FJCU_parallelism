#pragma once
#include <iostream>
#include<vector>
#include "Input2D.h"
using namespace std;
class Conv2D
{
	public:
		Conv2D(int num_filters, int kernel_size, Input2D previous_layer, activation_function);
		vector<vector<float>> conv(vector<vector<float>> input2D);
	private:
		int kernel_size;
		int num_filters;
		Input2D previous_layer;
		vector<vector<vector<vector<float>>>> initial_weights;
		vector<vector<vector<vector<float>>>> trained_weights;
		vector<vector<vector<vector<int>>>> filter_bank_size;
		vector<vector<vector<int>>> layer_input_size;
		vector<vector<vector<int>>> layer_output_size;
};