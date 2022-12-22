#pragma once
#include "AveragePooling2D.h"
#include "Flatten.h"

class Dense
{
public:
	Dense(int num_neurons ,string activation_function);
	Dense(int num_neurons ,Flatten previous_layer,string activation_function);
	Dense(int num_neurons,Dense previous_layer, string activation_function);
private:
	int num_neurons;
};

