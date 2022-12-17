#include "Sigmoid.h"

Sigmoid::Sigmoid(Conv2D previous_layer) {
    //previous_layer: Reference to the previous layer.  
    if (!previous_layer) {
        raise TypeError("The previous layer cannot be of Type 'None'. Please pass a valid layer to the 'previous_layer' parameter.")
    }
    // A reference to the layer that preceeds the current layer in the network architecture.
    this->previous_layer = previous_layer;
    //Size of the input to the layer.
    this->layer_input_size = this->previous_layer->layer_output_size;
     //Size of the output from the layer.
    this->layer_output_size = this->previous_layer->layer_output_size;
     //The layer_output attribute holds the latest output from the layer.
    //this->layer_output = NULL;
}