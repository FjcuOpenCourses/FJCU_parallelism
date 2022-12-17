#pragma once
#include    "ReLU.h"
#include    "Sigmoid.h"
using namespace std;

class AveragePooling2D
{
    public:
        AveragePooling2D(int pool_size,ReLU *previous_layer,int  stride);
        AveragePooling2D(int pool_size, Sigmoid *previous_layer, int  stride);
    private:
        int pool_size;
        ReLU *previous_relu_layer;
        Sigmoid *previous_sigmoid_layer;
        int  stride;
};

