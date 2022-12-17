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
using namespace MatrixLib;
CNN::CNN(){

}
vector<vector<float>> CNN::conv_(vector<vector<float>> img, vector<vector<float>> conv_filter){
    vector<vector<float>> conv_result;
    return conv_result;
}
vector<vector<vector<float>>> CNN::relu(vector<vector<vector<float>>> feature_map){
    vector<vector<vector<float>>> result = Numpy::Max(feature_map, 0);
    return result;
}
vector<vector<vector<float>>> CNN::conv(vector<vector<float>> img, vector<vector<vector<float>>> conv_filter)
{

}
vector<vector<vector<float>>> CNN::conv(vector<vector<vector<float>>> img, vector<vector<vector<float>>> conv_filter)
{

}
vector<vector<vector<float>>> CNN::pooling(vector<vector<vector<float>>> feature_map, int size = 2, int stride = 2)
{
    numpy.uint16((feature_map.shape[0] - size + 1) / stride + 1),
        numpy.uint16((feature_map.shape[1] - size + 1) / stride + 1),
        feature_map.shape[-1]
	vector<vector<vector<float>>> poolingresult  = Numpy::zeros();
    for map_num in range(feature_map.shape[-1]) :
        r2 = 0
        for r in numpy.arange(0, feature_map.shape[0] - size + 1, stride) :
            c2 = 0
            for c in numpy.arange(0, feature_map.shape[1] - size + 1, stride) :
                pool_out[r2, c2, map_num] = numpy.max([feature_map[r:r + size, c : c + size, map_num]])
                c2 = c2 + 1
                r2 = r2 + 
               
                for (int c = ) {
                } c in numpy.arange(0, feature_map.shape[1] - size + 1, stride) :
                    pool_out[r2, c2, map_num] = numpy.max([feature_map[r:r + size, c : c + size, map_num]])
                    c2 = c2 + 1
                    r2 = r2 + 1
	return poolingresult;
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
void CNN::setL2_filter(vector<vector<vector<float>>> value) {
    this->l2_filter = value;
}
vector<vector<vector<float>>> CNN::getL2_filter() {
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
void CNN::setL3_filter(vector<vector<vector<float>>> value) {
    this->l3_filter = value;
}
vector<vector<vector<float>>> CNN::getL3_filter() {
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