#include "Sigmoid.h"
#include "Numpy.h"
using namespace std;

Sigmoid::Sigmoid(Conv2D *previous_layer) {
    //previous_layer: Reference to the previous layer.  
    // A reference to the layer that preceeds the current layer in the network architecture.
    this->previous_layer = previous_layer;
    //Size of the input to the layer.
    this->setLayer_input_size(this->getPrevious_layer().getLayer_input_size());
     //Size of the output from the layer.
    this->setLayer_output_size(this->getPrevious_layer().getLayer_output_size());
     //The layer_output attribute holds the latest output from the layer.
    //this->layer_output = NULL;
}
void Sigmoid::sigmoid_layer(Conv2D layer_input) {
    this->setLayer_output_size(layer_input.getLayer_output_size());
    this->layer_output = Numpy::sigmoid(layer_input.);
}