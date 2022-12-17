#include "Conv2D.h"
#include <iostream>
#include <vector>

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
			cout << "Number of dimensions in the conv filter and the input do not match.\n";
		if (input2D_Dimension > 2 || initial_weight_Dimension > 3)				  // # Check if number of image channels matches the filter depth.
		{
			if (input2D[0].size() != (this -> initial_weights[0][0][0].size()))
			{
				cout << "Number of channels in both the input and the filter must match.\n";
			}
		}
		if ((this -> initial_weights[0].size()) != (this -> initial_weights[0][0][0].size()))
			cout << "A filter must be a square matrix. I.e. number of rows and columns must match.\n";
		if (this->initial_weights[0].size() % 2 == 0)
			cout << "A filter must have an odd size. I.e. number of rows and columns must be odd.\n";

		this -> layer_output = this -> conv_(input2D, this -> trained_weights)
	}
};