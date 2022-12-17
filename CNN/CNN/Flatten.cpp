#include	"Flatten.h"
#include	"AveragePooling2D.h"

Flatten::Flatten(AveragePooling2D *previous_layer) {
	this->previous_layer = previous_layer;
	//Size of the input to the layer.
	this->layer_input_size = previous_layer->
	//Size of the output from the layer.
	this->layer_output_size = functools.reduce(lambda x, y: x * y, self.previous_layer.layer_output_size);
	//The layer_output attribute holds the latest output from the layer.
	this->layer_output = NULL;
}
