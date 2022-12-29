#pragma once
#include <vector>
class ReLU;
class Flatten;
class Dense;
class Conv2D;
class MaxPooling2D;
class AveragePooling2D;

using namespace std;

class BaseLayer
{
public:
	vector<int>	layer_input_size, layer_output_size;
	BaseLayer* previousLayer;
};