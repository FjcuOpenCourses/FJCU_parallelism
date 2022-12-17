#pragma once
#include <iostream>
#include<vector>
using namespace std;
class Conv2D
{
	public:
		Conv2D(vector<float> inputShape);
		Conv2D(vector<vector<float>> inputShape);
		Conv2D(vector<vector<vector<float>>> inputShape);
	private:
		vector<vector<vector<float>>> input_shape;
		vector<int>layer_output_size;
};