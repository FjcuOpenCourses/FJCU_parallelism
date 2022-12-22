#include	"Dense.h"
#include	"AveragePooling2D.h"
Dense::Dense(int num_neurons, string activation_function) {
    this->num_neurons = num_neurons;
    if (activation_function._Equal("relu")) {
        this->ac
    }
    if (activation_function == "sigmoid") {

    }
    if (activation_function == "softmax") {

    }
}

Dense::Dense(int num_neurons, Flatten previous_layer, string activation_function) {
    this(num_neurons, activation_function);

}
Dense::Dense(int num_neurons, Dense previous_layer, string activation_function) {

        # Validating the activation function

        else:
    raise ValueError("The specified activation function '{activation_function}' is not among the supported activation functions {supported_activation_functions}. Please use one of the supported functions.".format(activation_function = activation_function, supported_activation_functions = supported_activation_functions))

        self.activation_function = activation_function

        if previous_layer is None :
    raise TypeError("The previous layer cannot be of Type 'None'. Please pass a valid layer to the 'previous_layer' parameter.")
        # A reference to the layer that preceeds the current layer in the network architecture.
        self.previous_layer = previous_layer

        if type(self.previous_layer.layer_output_size) in[list, tuple, numpy.ndarray] and len(self.previous_layer.layer_output_size) > 1:
    raise ValueError("The input to the dense layer must be of type int but {sh} found.".format(sh = type(self.previous_layer.layer_output_size)))
        # Initializing the weights of the layer.
        self.initial_weights = numpy.random.uniform(low = -0.1,
            high = 0.1,
            size = (self.previous_layer.layer_output_size, self.num_neurons))

        # The trained weights of the layer.Only assigned a value after the network is trained(i.e.the train_network() function completes).
        # Just initialized to be equal to the initial weights
        self.trained_weights = self.initial_weights.copy()

        # Size of the input to the layer.
        self.layer_input_size = self.previous_layer.layer_output_size

        # Size of the output from the layer.
        self.layer_output_size = num_neurons

        # The layer_output attribute holds the latest output from the layer.
        self.layer_output = None
}

