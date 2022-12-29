#pragma once
#include "Conv2D.h"
#include "ActivationFunction.h"
#include "BaseLayer.h"

using namespace std;
class ReLU: public BaseLayer
{
	public:
		ReLU(Conv2D *previous_layer);
		BaseLayer getPreviousLayer();
	private:
		BaseLayer *previous_layer;
};