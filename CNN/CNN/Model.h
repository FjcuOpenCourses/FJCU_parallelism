#pragma once
#include "Dense.h"
class Model
{
public:
	Model(Dense last_layer,int epochs,float learning_rate);
	//void train(train_inputs = train_inputs, train_outputs = train_outputs);
	//predict(data_inputs = train_inputs);
	void summary();
};

