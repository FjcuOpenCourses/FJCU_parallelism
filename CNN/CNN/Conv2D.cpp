#include	"Conv2D.h"
#include	<iostream>
#include	<vector>
#include	"AveragePooling2D.h"
#include	"Input2D.h"
#include	<stdio.h>
#include	<stdlib.h> /* 亂數相關函數 */
#include	<time.h>   /* 時間相關函數 */

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
		if (num_filters <= 0) {
			std::cout << "Number of filters cannot be <= 0. Please pass a valid value to the 'num_filters' parameter.\n";
			return;
		}
		this->num_filters = num_filters;

		if (kernel_size <= 0) {
			std::cout << "The kernel size cannot be <= 0. Please pass a valid value to the 'kernel_size' parameter.\n";
			return;
		}
		// # Kernel size of each filter.
		this->kernel_size = kernel_size;
	// # Validating the activation function
		if (activation_function.empty()) {
			this->activation = NULL;
		}
		if(activation_function._Equal("relu")) {
			this->activation = relu;
		}
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
	for (int i = 0; i < filter_bank_size; i++)
	{
		initial_weights[i] = (rand() % 2 / 10) - 0.1;
	}
	/*this->initial_weights = numpy.random.uniform(low = -0.1,
		high = 0.1,
		size = self.filter_bank_size);*/

	// # The trained filters of the conv layer.Only assigned a value after the network is trained(i.e.the train_network() function completes).
	// # Just initialized to be equal to the initial filters
	for (int i = 0; i < initial_weights.size(); i++)
	{
		trained_weights[i] = initial_weights[i];
	}
	// self.trained_weights = self.initial_weights.copy()

	// # Size of the input to the layer.
	for (int i = 0; i < this -> layer_output_size; i++)
	{
		this -> layer_input_size[i] = this -> previous_layer.layer_output_size[i];
	}
	// self.layer_input_size = self.previous_layer.layer_output_size

	// # Size of the output from the layer.
	// # Later, it must conider strides and paddings
	layer_output_size = 
	
	// self.layer_output_size = (self.previous_layer.layer_output_size[0] - self.kernel_size + 1,
		// self.previous_layer.layer_output_size[1] - self.kernel_size + 1,
		// num_filters)

	// # The layer_output attribute holds the latest output from the layer.
	// self.layer_output = None
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