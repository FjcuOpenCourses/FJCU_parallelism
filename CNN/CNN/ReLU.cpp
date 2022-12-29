#include "ReLU.h"
#include "Conv2D.h"

using namespace std;

ReLU::ReLU(Conv2D *previous_layer) {
	this->previous_layer = previous_layer;
	this->layer_input_size = previous_layer->getLayer_input_size();
	this->layer_output_size = previous_layer->getLayer_output_size();
}

Conv2D	ReLU::getPreviousLayer() {
	return this->previous_layer;
}
