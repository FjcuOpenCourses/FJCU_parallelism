#pragma once
#include <iostream>
#include<vector>
using namespace std;
class Input2D
{
public:
	Input2D(vector<int> inputShape);
private:
	vector<int> input_shape;
	vector<int>	layer_input_size, layer_output_size;
};