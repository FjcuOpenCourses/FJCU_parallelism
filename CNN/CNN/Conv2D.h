#pragma once
#include <iostream>
#include<vector>
#include "Input2D.h"
using namespace std;
class Conv2D
{
	public:
		Conv2D();
		vector<vector<float>> conv(vector<vector<float>> input2D);
	private:
		vector<vector<vector<vector<float>>>> initial_weights;
		vector<vector<vector<vector<float>>>> trained_weights;
		Input2D previous_layer;
		int kernel_size;
		int num_filters;
		vector<vector<vector<vector<int>>>> filter_bank_size;
		vector<vector<vector<int>>> layer_input_size;
		vector<vector<vector<int>>> layer_output_size;

};