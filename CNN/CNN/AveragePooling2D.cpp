#include "AveragePooling2D.h"
#include"ReLU.h"


AveragePooling2D::AveragePooling2D(int pool_size, ReLU previous_layer, int  stride) {
	this->pool_size = pool_size;
	this->previous_layer = previous_layer;
	this->stride = stride;
}