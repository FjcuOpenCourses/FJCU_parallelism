#include	"Conv2D.h"
#include	<iostream>
#include	<vector>
#include	"AveragePooling2D.h"
#include	"Input2D.h"

using namespace std;

Conv2D::Conv2D(int num_filters, int kernel_size, Input2D* previous_layer, string activation_function)
{
	/*
	num_filters: Number of filters in the convolution layer.
	kernel_size : Kernel size of the filter.
	previous_layer : A reference to the previous layer.
	activation_function = None : The name of the activation function to be used in the conv layer.If None,
						  then no activation function is applied besides the convolution operation.
						  The activation function can be applied by a separate layer.
	*/
	

	if (num_filters <= 0)
		std::cout << "Number of filters cannot be <= 0. Please pass a valid value to the 'num_filters' parameter.\n";
	// # Number of filters in the conv layer.
	this->num_filters = num_filters;

	if (kernel_size <= 0)
		std::cout << "The kernel size cannot be <= 0. Please pass a valid value to the 'kernel_size' parameter.\n";
	// # Kernel size of each filter.
	this->kernel_size = kernel_size;

	// # Validating the activation function
	if (activation_function == None)
		this -> activation = None;
	else if (activation_function == "relu")
		this -> activation = relu;
	else if (activation_function == "sigmoid")
		this -> activation = sigmoid;
	else if (activation_function == "softmax") :
		cout << "The softmax activation function cannot be used in a conv layer.\n";
	else
		cout << "The specified activation function " << activation_function << " is not among the supported activation functions " << supported_activation_functions << ".Please use one of the supported functions.\n";

	// # The activation function used in the current layer.
	this -> activation_function = activation_function;


	if (previous_layer == None)
		cout << "The previous layer cannot be of Type 'None'. Please pass a valid layer to the 'previous_layer' parameter.\n";
	// # A reference to the layer that preceeds the current layer in the network architecture.
	this -> previous_layer = previous_layer;

	// # A reference to the bank of filters.
	this -> filter_bank_size = (this -> num_filters,
		this -> kernel_size,
		this -> kernel_size,
		this -> previous_layer.layer_output_size[-1]);
	


	unsigned seed;
	seed = (unsigned)time(NULL); // 取得時間序列
	srand(seed);				 // 以時間序列當亂數種子
	// # Initializing the filters of the conv layer.
	for (int i = 0; i < filter_bank_size)
	this -> initial_weights = numpy.random.uniform(low = -0.1,
		high = 0.1,
		size = self.filter_bank_size);
}
Conv2D::Conv2D(int num_filters, int kernel_size, AveragePooling2D *previous_layer, string activation_function) {
	this->num_filters = num_filters;
	this->kernel_size = kernel_size;
	this->previous_average_pooling_layer = previous_layer;

}
Conv2D::Conv2D(int num_filters, int kernel_size, MaxPooling2D *previous_layer, string activation_function) {
	this->num_filters = num_filters;
	this->kernel_size = kernel_size;
	this->previous_max_pooling_layer = previous_layer;

}


vector<vector<float>> Conv2D::conv(vector<vector<float>> input2D){
		/*
			Convolves the input (input2D) by a filter bank.
        
			input2D: The input to be convolved by the filter bank.
			The conv() method saves the result of convolving the input by the filter bank in the layer_output attribute.
		*/
		int input2D_Dimension = 0, initial_weight_Dimension = 0;
		if (input2D.size() > 1)		input2D_Dimension++;
		if (input2D[0].size() > 1)		input2D_Dimension++;
		if (this -> initial_weights.size() > 1)		initial_weight_Dimension++;
		if (this -> initial_weights[0].size() > 1)		initial_weight_Dimension++;
		if (this -> initial_weights[0][0].size() > 1)		initial_weight_Dimension++;
		if (this -> initial_weights[0][0][0].size() > 1)		initial_weight_Dimension++;
		if (input2D_Dimension != initial_weight_Dimension - 1)                    // # Check if there is a match in the number of dimensions between the image and the filters.
			std::cout << "Number of dimensions in the conv filter and the input do not match.\n";
		if (input2D_Dimension > 2 || initial_weight_Dimension > 3)				  // # Check if number of image channels matches the filter depth.
		{
			if (input2D[0].size() != (this -> initial_weights[0][0][0].size()))
			{
				std::cout << "Number of channels in both the input and the filter must match.\n";
			}
		}
		if ((this -> initial_weights[0].size()) != (this -> initial_weights[0][0].size())) // # Check if filter dimensions are equal.
			std::cout << "A filter must be a square matrix. I.e. number of rows and columns must match.\n";
		if (this->initial_weights[0].size() % 2 == 0)									   // # Check if filter diemnsions are odd.
			std::cout << "A filter must have an odd size. I.e. number of rows and columns must be odd.\n";

		this -> layer_output = this -> conv_(input2D, this -> trained_weights);
	}
};

vector<int> Conv2D::getLayer_input_size() {
	return this->layer_input_size;
}
vector<int> Conv2D::getLayer_output_size() {
	return this->layer_output_size;
}