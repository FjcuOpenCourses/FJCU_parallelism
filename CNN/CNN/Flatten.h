#pragma once
#include	<vector>

class BaseLayer;
class AveragePooling2D;
using namespace std;

class Flatten :public BaseLayer
{
public:
	Flatten(AveragePooling2D *previous_layer);
private:
	AveragePooling2D *previous_layer;
	vector<int> layer_input_size;
	vector<int> layer_output_size;
};

