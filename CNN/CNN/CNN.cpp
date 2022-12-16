#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <vector>

using namespace std;

vector<vector<int>> conv_(vector<vector<float>> img, vector<vector<float>> conv_filter)
{
	vector<vector<int>> b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i].push_back(0);
		}
	}
}

vector<vector<int>> conv(vector<vector<float>> input2D)
{
    /*
        Convolves the input(input2D) by a filter bank.

        input2D : The input to be convolved by the filter bank.
        The conv() method saves the result of convolving the input by the filter bank in the layer_output attribute.
    */

    /*  參考用
    * 
        int rows = 3;
        int columns = 4;
        vector<vector<int>> vec1( rows , vector<int> (columns));

        初始化後
        int rows = ans[0].size();  //列
        int column = ans.size();   //行
    */
    
    if (input2D.size() != 1 && input2D[0] != 1)
    {

    }
    if (input2D.size() != length(this -> initial_weights[0].size()) - 1) // # Check if there is a match in the number of dimensions between the imageand the filters.
        cout << "Number of dimensions in the conv filter and the input do not match." << endl;
    /*
    # Initializing the filters of the conv layer.
        self.initial_weights = numpy.random.uniform(low=-0.1,
                                                    high=0.1,
                                                    size=self.filter_bank_size)
    */


        if len(input2D.shape) != len(self.initial_weights.shape) - 1 : # Check if there is a match in the number of dimensions between the imageand the filters.
            raise ValueError("Number of dimensions in the conv filter and the input do not match.")
        if len(input2D.shape) > 2 or len(self.initial_weights.shape) > 3: # Check if number of image channels matches the filter depth.
        if input2D.shape[-1] != self.initial_weights.shape[-1]:
            raise ValueError("Number of channels in both the input and the filter must match.")
        if self.initial_weights.shape[1] != self.initial_weights.shape[2] : # Check if filter dimensions are equal.
            raise ValueError('A filter must be a square matrix. I.e. number of rows and columns must match.')
        if self.initial_weights.shape[1] % 2 == 0: # Check if filter diemnsions are odd.
            raise ValueError('A filter must have an odd size. I.e. number of rows and columns must be odd.')

        self.layer_output = self.conv_(input2D, self.trained_weights)
}

vector<vector<vector<int>>> pooling(vector<vector<vector<float>>> feature_map, int size = 2, int stride = 2)
{

}

vector<vector<vector<int>>> relu(vector<vector<vector<float>>> feature_map)
{

}

int main()
{
	std::cout << "Hello World!\n";
}