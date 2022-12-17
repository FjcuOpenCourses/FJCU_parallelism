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

CNN::CNN(){

}
vector<vector<float>> CNN::conv_(vector<vector<float>> img, vector<vector<float>> conv_filter){
    vector<vector<float>> conv_result;
    return conv_result;
}
vector<vector<vector<float>>> CNN::relu(vector<vector<vector<float>>> feature_map){return  Numpy::Max(feature_map, 0);}

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
    for (int map_num = 0; map_num < size3;map_num++) {
        int r2 = 0;
        vector<int> filter1 = Numpy::arange(0, Numpy::shape(feature_map, 0) - size + 1, stride);
        for (int r : filter1) {
            int c2 = 0;
            vector<int> filter2 = Numpy::arange(0, Numpy::shape(feature_map, 1) - size + 1, stride);
            for (int c : filter2) {
                pool_out[r2][c2][map_num] = Numpy::Max(feature_map,r,r+size,c,c+size,map_num);
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
     this->l1_feature_map_relu_pool=value;
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