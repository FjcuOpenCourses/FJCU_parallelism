#include "MaxPooling2D.h"
#include "ReLU.h"
#include "Numpy.h"

MaxPooling2D::MaxPooling2D(int pool_size, ReLU *previous_layer, int stride) {
	this->pool_size = pool_size;
	this->previous_layer = previous_layer;
	this->stride = stride;
}
void MaxPooling2D::max_pooling(Input2D *input2D) {

    int size1 = (Numpy::shape(input2D, 0) - size + 1) / stride + 1;
    int size2 = (Numpy::shape(input2D, 1) - size + 1) / stride + 1;
    int size3 = Numpy::shape(input2D, -1);

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