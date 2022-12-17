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
		if (input2D[0][0].size() > 1)		input2D_Dimension++;
		if (input2D[0][0][0].size() > 1)		input2D_Dimension++;
		if (this -> initial_weights.size() > 1)		initial_weight_Dimension++;
		if (this -> initial_weights[0].size() > 1)		initial_weight_Dimension++;
		if (this -> initial_weights[0][0].size() > 1)		initial_weight_Dimension++;
		if (this -> initial_weights[0][0][0].size() > 1)		initial_weight_Dimension++;
		if (input2D_Dimension != initial_weight_Dimension - 1)                    // # Check if there is a match in the number of dimensions between the image and the filters.
			cout << "Number of dimensions in the conv filter and the input do not match.";
		if (input2D_Dimension > 2 || initial_weight_Dimension > 3)				  // # Check if number of image channels matches the filter depth.
		{
			if (input2D[0][0][0].size() != initial_weights[0][0][0].size())
			{

			}
		}
		/*
			if len(input2D.shape) != len(self.initial_weights.shape) - 1: # Check if there is a match in the number of dimensions between the image and the filters.
				raise ValueError("Number of dimensions in the conv filter and the input do not match.")  
			if len(input2D.shape) > 2 or len(self.initial_weights.shape) > 3: # Check if number of image channels matches the filter depth.
				if input2D.shape[-1] != self.initial_weights.shape[-1]:
					raise ValueError("Number of channels in both the input and the filter must match.")
			if self.initial_weights.shape[1] != self.initial_weights.shape[2]: # Check if filter dimensions are equal.
				raise ValueError('A filter must be a square matrix. I.e. number of rows and columns must match.')
			if self.initial_weights.shape[1]%2==0: # Check if filter diemnsions are odd.
				raise ValueError('A filter must have an odd size. I.e. number of rows and columns must be odd.')

			self.layer_output = self.conv_(input2D, self.trained_weights)
		*/
	}
};