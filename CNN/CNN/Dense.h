#pragma once
#include	<string>
class BaseLayer;
class Flatten;
class AveragePooling2D;

class Dense :public BaseLayer
{
public:
	Dense(int num_neurons ,Flatten *previous_layer,string activation_function);
	Dense(int num_neurons,Dense *previous_layer, string activation_function);
};

