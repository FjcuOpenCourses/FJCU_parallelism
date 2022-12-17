#pragma once
#include "Conv2D.h"
class ReLU
{
	public:
		ReLU(Conv2D previous_layer);
	private:
		vector<int>	layer_input_size;
		vector<int> layer_output_size;
		Conv2D previous_layer;
};

