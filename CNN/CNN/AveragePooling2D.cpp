#include "AveragePooling2D.h"
#include"ReLU.h"

using namespace std;

AveragePooling2D::AveragePooling2D(int pool_size, ReLU *previous_layer, int  stride) {
	this->pool_size = pool_size;
	this->previous_relu_layer = previous_layer;
	this->stride = stride;
}
AveragePooling2D::AveragePooling2D(int pool_size, Sigmoid	*previous_layer, int  stride) {
	this->pool_size = pool_size;
	this->previous_sigmoid_layer = previous_layer;
	this->stride = stride;
}
