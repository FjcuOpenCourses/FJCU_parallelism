#include "ReLU.h"


ReLU::ReLU(Conv2D previous_layer) {
	//A reference to the layer that preceeds the current layer in the network architecture.
	this->previous_layer = previous_layer;
	//Size of the input to the layer.
	this->layer_input_size = this->previous_layer.getLayer_input_size();
	//Size of the output from the layer.
	this->layer_output_size = this->previous_layer.getLayer_output_size();
	//The layer_output attribute holds the latest output from the layer.
}
