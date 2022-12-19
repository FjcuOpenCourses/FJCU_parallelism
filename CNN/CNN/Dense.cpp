#include	"Dense.h"
#include	"Flatten.h"
#include	"AveragePooling2D.h"

Dense::Dense(int num_neurons, Flatten *previous_layer, string activation_function) : BaseLayer(*previousLayer) {

}
Dense::Dense(int num_neurons, Dense *previous_layer, string activation_function):BaseLayer(*previousLayer) {

}

