#pragma once
#include <iostream>
#include<vector>
using namespace std;
class Input2D
{
public:
	Input2D(vector<float> inputShape);
	Input2D(vector<vector<float>> inputShape);
	Input2D(vector<vector<vector<float>>> inputShape);
private:
	vector<vector<vector<float>>> input_shape;
	vector<int>layer_output_size;
};