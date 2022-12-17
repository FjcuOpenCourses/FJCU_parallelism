#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include "Numpy.h"
#include <cmath>
#include "Numpy.h"
using namespace std;
using namespace MatrixLib;
class CNN {
    vector<vector<float>> conv_(vector<vector<float>> img, vector<vector<float>> conv_filter)
    {
        vector<vector<float>> conv_result;
        return conv_result;
    }
};

vector<vector<int>> conv(vector<vector<float>> input2D)
{
    /*
        Convolves the input(input2D) by a filter bank.

        input2D : The input to be convolved by the filter bank.
        The conv() method saves the result of convolving the input by the filter bank in the layer_output attribute.
    */

    /*    
        int rows = 3;
        int columns = 4;
        vector<vector<int>> vec1(rows , vector<int> (columns));

        int rows = ans[0].size();  //rows
        int column = ans.size();   //columns
    */

    // conv first if
    int input_dimension, initial_weights_shapeHandle;
    for (int i = 0; i < 10; i++)
    {
        if (input2D.size[]() > 1)
        {

        }
    }
    if (input2D.size() > 1 && input2D[0].size() > 1)
        input_dimension = 2;
    else
        input_dimension = 1;
    /*
    # Initializing the filters of the conv layer.
        self.initial_weights = numpy.random.uniform(low=-0.1,
                                                    high=0.1,
                                                    size=self.filter_bank_size)
    */
    if (this -> initial_weights.size() > 1 && this -> initial_weights[0].size() > 1)
        initial_weights_shapeHandle = 1;
    else if (this->initial_weights.size() == 1 && this->initial_weights[0].size() > 1)
        initial_weights_shapeHandle = 0;
    if (input_dimension != initial_weights_shapeHandle) // # Check if there is a match in the number of dimensions between the imageand the filters.
        cout << "Number of dimensions in the conv filter and the input do not match." << endl;


    // conv second if



        // if len(input2D.shape) != len(self.initial_weights.shape) - 1 : # Check if there is a match in the number of dimensions between the imageand the filters.
            // raise ValueError("Number of dimensions in the conv filter and the input do not match.")
        if len(input2D.shape) > 2 or len(self.initial_weights.shape) > 3: # Check if number of image channels matches the filter depth.
        if input2D.shape[-1] != self.initial_weights.shape[-1]:
            raise ValueError("Number of channels in both the input and the filter must match.")
        if self.initial_weights.shape[1] != self.initial_weights.shape[2] : # Check if filter dimensions are equal.
            raise ValueError('A filter must be a square matrix. I.e. number of rows and columns must match.')
        if self.initial_weights.shape[1] % 2 == 0: # Check if filter diemnsions are odd.
            raise ValueError('A filter must have an odd size. I.e. number of rows and columns must be odd.')

        self.layer_output = self.conv_(input2D, self.trained_weights)
}

vector<vector<vector<float>>> pooling(vector<vector<vector<float>>> feature_map, int size = 2, int stride = 2)
{
	vector<vector<vector<float>>> poolingresult;

	return poolingresult;
}

vector<vector<vector<float>>> relu(vector<vector<vector<float>>> feature_map)
{
    vector<vector<vector<float>>> result = Numpy::Max(feature_map, 0);
	return result;
}

int main()
{
	
}