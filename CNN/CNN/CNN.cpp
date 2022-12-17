#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include "Numpy.h"
#include <cmath>
#include "Numpy.h"
#include "Cnn.h"
using namespace std;

CNN::CNN() {

    <<<<<< < HEAD
        input2D : The input to be convolved by the filter bank.
        The conv() method saves the result of convolving the input by the filter bank in the layer_output attribute.
        * /

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
    if (this->initial_weights.size() > 1 && this->initial_weights[0].size() > 1)
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
                ====== =
                >>>>>> > 0ea7ccf925e536087a4ec1c8e1ced99d13528f72
}
vector<vector<float>> CNN::conv_(vector<vector<float>> img, vector<vector<float>> conv_filter) {
    vector<vector<float>> conv_result;
    return conv_result;
}
vector<vector<vector<float>>> CNN::relu(vector<vector<vector<float>>> feature_map) { return  Numpy::Max(feature_map, 0); }

vector<vector<vector<float>>> CNN::conv(vector<vector<float>> img, vector<vector<vector<float>>> conv_filter)
{

}
vector<vector<vector<float>>> CNN::conv(vector<vector<vector<float>>> img, vector<vector<vector<vector<float>>>> conv_filter)
{

}
vector<vector<vector<float>>> CNN::pooling(vector<vector<vector<float>>> feature_map, int size, int stride)
{
    int size1 = (Numpy::shape(feature_map, 0) - size + 1) / stride + 1;
    int size2 = (Numpy::shape(feature_map, 1) - size + 1) / stride + 1;
    int size3 = Numpy::shape(feature_map, -1);

    vector<vector<vector<float>>> pool_out = Numpy::zeros(size1, size2, size3);
    for (int map_num = 0; map_num < size3; map_num++) {
        int r2 = 0;
        vector<int> filter1 = Numpy::arange(0, Numpy::shape(feature_map, 0) - size + 1, stride);
        for (int r : filter1) {
            int c2 = 0;
            vector<int> filter2 = Numpy::arange(0, Numpy::shape(feature_map, 1) - size + 1, stride);
            for (int c : filter2) {
                pool_out[r2][c2][map_num] = Numpy::Max(feature_map, r, r + size, c, c + size, map_num);
            }
        }
    }
    return pool_out;
}
void CNN::setL1_filter(vector<vector<vector<float>>> value) {
    this->l1_filter = value;
}
vector<vector<vector<float>>> CNN::getL1_filter() {
    return this->l1_filter;
}
void CNN::setL1_feature_map(vector<vector<vector<float>>> value) {
    this->l1_feature_map = value;
}
vector<vector<vector<float>>> CNN::getL1_feature_map() {
    return this->l1_feature_map;
}
void  CNN::setL1_feature_map_relu(vector<vector<vector<float>>> value) {
    this->l1_feature_map_relu = value;
}
vector<vector<vector<float>>> CNN::getL1_feature_map_relu() {
    return this->l1_feature_map_relu;
}
void  CNN::setL1_feature_map_relu_pool(vector<vector<vector<float>>> value) {
    this->l1_feature_map_relu_pool = value;
}
vector<vector<vector<float>>>  CNN::getL1_feature_map_relu_pool() {
    return this->l1_feature_map_relu_pool;
}
void CNN::setL2_filter(vector<vector<vector<vector<float>>>> value) {
    this->l2_filter = value;
}
vector<vector<vector<vector<float>>>> CNN::getL2_filter() {
    return this->l2_filter;
}
void CNN::setL2_feature_map(vector<vector<vector<float>>> value) {
    this->l2_feature_map = value;
}
vector<vector<vector<float>>> CNN::getL2_feature_map() {
    return this->l2_feature_map;
}
void  CNN::setL2_feature_map_relu(vector<vector<vector<float>>> value) {
    this->l2_feature_map_relu = value;
}
vector<vector<vector<float>>> CNN::getL2_feature_map_relu() {
    return this->l2_feature_map_relu;
}
void  CNN::setL2_feature_map_relu_pool(vector<vector<vector<float>>> value) {
    this->l2_feature_map_relu_pool = value;
}
vector<vector<vector<float>>>  CNN::getL2_feature_map_relu_pool() {
    return this->l2_feature_map_relu_pool;
}
void CNN::setL3_filter(vector<vector<vector<vector<float>>>> value) {
    this->l3_filter = value;
}
vector<vector<vector<vector<float>>>> CNN::getL3_filter() {
    return this->l3_filter;
}
void CNN::setL3_feature_map(vector<vector<vector<float>>> value) {
    this->l3_feature_map = value;
}
vector<vector<vector<float>>> CNN::getL3_feature_map() {
    return this->l3_feature_map;
}
void  CNN::setL3_feature_map_relu(vector<vector<vector<float>>> value) {
    this->l3_feature_map_relu = value;
}
vector<vector<vector<float>>> CNN::getL3_feature_map_relu() {
    return this->l3_feature_map_relu;
}
void  CNN::setL3_feature_map_relu_pool(vector<vector<vector<float>>> value) {
    this->l3_feature_map_relu_pool = value;
}
vector<vector<vector<float>>>  CNN::getL3_feature_map_relu_pool() {
    return this->l3_feature_map_relu_pool;
}