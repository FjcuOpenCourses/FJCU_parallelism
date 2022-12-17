//import skimage.data
//#include "matplotlibcpp.h"
#include "Numpy.h"
#include "CNN.h";
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//namespace plt = matplotlibcpp;

vector<vector<vector<float>>> First_conv_layer() {
 //First conv layer
    vector<vector<vector<float>>> l1_filter = Numpy::zeros(2, 3, 3);
    l1_filter[0][0] = {-1, 0, 1};
    l1_filter[0][1] = {-1, 0, 1};
    l1_filter[0][2] = { -1, 0, 1 };
    l1_filter[1][0] = { 1,1,1};
    l1_filter[1][1] = { 0,0,0 };
    l1_filter[1][2] = { -1, -1, -1 };
    return l1_filter;
}
vector<vector<float>> readingData(string fileName) {
    vector<vector<float>> data;
    ifstream input(fileName);
    for (std::string line; getline(input, line); )
    {

    }
    return data;
}
int main() {
    CNN model;
    model.setL1_filter(First_conv_layer());
    cout << "\n**Working with conv layer 1**" << endl;
    vector<vector<float>> img = readingData("data.txt");
    model.setL1_feature_map(model.conv(img,model.getL1_filter()));
    cout << "\n**ReLU**" << endl;
    model.setL1_feature_map_relu(model.relu(model.getL1_feature_map()));
    cout << "\n**Pooling**" << endl;
    model.setL1_feature_map_relu_pool(model.pooling(model.getL1_feature_map_relu(), 2, 2));
    cout << "**End of conv layer 1**\n" << endl;

    //Second conv layer
    model.setL2_filter(Numpy::Rand(3, 5, 5, Numpy::shape(model.getL1_feature_map_relu_pool(), -1)));
    cout << "\n**Working with conv layer 2**" << endl;
    model.setL2_feature_map(model.conv(model.getL1_feature_map_relu_pool(), model.getL2_filter()));
    cout << "\n**ReLU**" << endl;
    model.setL2_feature_map_relu(model.relu(model.getL2_feature_map()));
    cout << "\n**Pooling**" << endl;
    model.setL2_feature_map_relu_pool(model.pooling(model.getL2_feature_map_relu(), 2, 2));
    cout << "**End of conv layer 2**\n" << endl;
    
    //Third conv layer
    
    model.setL3_filter(Numpy::Rand(1, 7, 7, Numpy::shape(model.getL2_feature_map_relu_pool(), -1)));
    cout << "\n**Working with conv layer 3**" << endl;
    model.setL3_feature_map(model.conv(model.getL2_feature_map_relu_pool(), model.getL3_filter()));
    cout << "\n**ReLU**" << endl;
    model.setL3_feature_map_relu(model.relu(model.getL3_feature_map()));
    cout << "\n**Pooling**" << endl;
    model.setL3_feature_map_relu_pool(model.pooling(model.getL3_feature_map_relu(), 2, 2));
    cout << "**End of conv layer 3**\n" << endl;
}








