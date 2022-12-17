#pragma once
#include "ReLU.h"

class AveragePooling2D
{
    public:
        AveragePooling2D(int pool_size,ReLU previous_layer,int  stride);
    private:
        int pool_size;
        ReLU previous_layer;
        int  stride;
};

