#pragma once
#include "Conv2D.h"
class Sigmoid
{
public:
	Sigmoid(Conv2D *previous_layer);
	void sigmoid_layer(Conv2D layer_input);
	Conv2D getPrevious_layer();
	void setLayer_input_size(vector<int> value);
	void setLayer_output_size(vector<int> value);

private:
	vector<int>	layer_input_size;
	vector<int>	layer_output_size;
	Conv2D *previous_layer;
};

