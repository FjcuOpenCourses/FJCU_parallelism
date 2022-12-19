#pragma once
#include "Conv2D.h"
#include "ActivationFunction.h"
using namespace std;
class ReLU: private ActivtionFunction
{
	public:
		ReLU(Conv2D *previous_layer);
	private:
		vector<int>	layer_input_size,layer_output_size;
		Conv2D *previous_layer;
};

