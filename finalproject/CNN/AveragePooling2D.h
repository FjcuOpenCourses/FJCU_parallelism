#pragma once
class ReLU;
class Sigmoid;
class BaseLayer;

using namespace std;
class AveragePooling2D:public BaseLayer
{
    public:
        AveragePooling2D(int pool_size,ReLU *previous_layer,int  stride);
        AveragePooling2D(int pool_size, Sigmoid *previous_layer, int  stride);
    private:
        int pool_size;
        BaseLayer *previous_layer;
        int  stride;
};