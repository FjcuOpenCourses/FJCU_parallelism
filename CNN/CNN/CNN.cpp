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



}
vector<vector<float>> CNN::conv_(vector<vector<float>> input2D, vector<vector<float>> conv_filter)
{
    float input2D_row = (float)input2D.size(), input2D_col = (float)input2D[0].size();                          //row = 1, cols = 0;
    float conv_filter_row = (float)conv_filter.size(), conv_filter_col = (float)conv_filter[0].size();       //row = 1, cols = 0;

    vector<vector<vector<float>>> result = Numpy::zeros(input2D_col, input2D_row, conv_filter_col);     //result
    vector<vector<float>> conv_result;

    //Numpy::shape(input2D, 0) = (float)input2D[0].size();              //??uncertain 

    vector<float> arange1, arange2;
    vector<float> floor;

    float filter_bank_size[4];
    float curr_region[1][1], curr_result[1][1];

    arange1 = Numpy::arange(filter_bank_size[1] / 2, Numpy::shape(input2D, 0) - filter_bank_size[1] / 2 + 1);
    arange2 = Numpy::arange(filter_bank_size[1] / 2, Numpy::shape(input2D, 1) - filter_bank_size[1] / 2 + 1);
    floor[0] = filter_bank_size[1] / 2.0;



    for (float r = 0; r < arange1; r++)
    {
        for (float c = 0; c < arange2; c++)
        {
            if (input2D.size() == 2)
            {
                curr_region[r][c] = input2D[r - Numpy::Floor(floor):r + Numpy::Ceil(floor),
                    c - Numpy::Floor(floor)) :c + Numpy::Ceil(floor)];

            }
            else
            {
                curr_region[r][c] = input2D[r - Numpy::Floor(floor):r + Numpy::Ceil(floor),
                    c - Numpy::Floor(floor)) : c + Numpy::Ceil(floor), : ];
            }
        }
    }
    for (float filter_idx = 0; filter_idx < conv_filter_col; filter_idx++)
    {
        curr_result = curr_region * conv_filter[filter_idx];
        conv_sum = numpy.sum(curr_result);    //¯x°}¨D©M

        if (activation == NULL)
        {
            result[r][c][filter_idx] = conv_sum;
        }
        else
        {
            result[r][c][filter_idx] = activation(conv_sum);
        }
    }

    conv_result = result[(filter_bank_size[1] / 2.0) : Numpy::shape(result, 0) - (filter_bank_size[1] / 2.0)][(filter_bank_size[1] / 2.0) : Numpy::shape(result, 1) - (filter_bank_size[1] / 2.0)][:];
    
    return conv_result;
}
vector<vector<vector<float>>> CNN::relu(vector<vector<vector<float>>> feature_map) {
    return  Numpy::Max(feature_map, 0); 
}

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