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
    showImageResult(img);
}
void showImageResult(vector<vector<float>>img) {
    //Graphing results
        fig0, ax0 = matplotlib.pyplot.subplots(nrows = 1, ncols = 1)
        ax0.imshow(img).set_cmap("gray")
        ax0.set_title("Input Image")
        ax0.get_xaxis().set_ticks([])
        ax0.get_yaxis().set_ticks([])
        matplotlib.pyplot.savefig("in_img.png", bbox_inches = "tight")
        matplotlib.pyplot.close(fig0)

    // Layer 1
        fig1, ax1 = matplotlib.pyplot.subplots(nrows = 3, ncols = 2)
        ax1[0, 0].imshow(l1_feature_map[:, : , 0]).set_cmap("gray")
        ax1[0, 0].get_xaxis().set_ticks([])
        ax1[0, 0].get_yaxis().set_ticks([])
        ax1[0, 0].set_title("L1-Map1")

        ax1[0, 1].imshow(l1_feature_map[:, : , 1]).set_cmap("gray")
        ax1[0, 1].get_xaxis().set_ticks([])
        ax1[0, 1].get_yaxis().set_ticks([])
        ax1[0, 1].set_title("L1-Map2")

        ax1[1, 0].imshow(l1_feature_map_relu[:, : , 0]).set_cmap("gray")
        ax1[1, 0].get_xaxis().set_ticks([])
        ax1[1, 0].get_yaxis().set_ticks([])
        ax1[1, 0].set_title("L1-Map1ReLU")

        ax1[1, 1].imshow(l1_feature_map_relu[:, : , 1]).set_cmap("gray")
        ax1[1, 1].get_xaxis().set_ticks([])
        ax1[1, 1].get_yaxis().set_ticks([])
        ax1[1, 1].set_title("L1-Map2ReLU")

        ax1[2, 0].imshow(l1_feature_map_relu_pool[:, : , 0]).set_cmap("gray")
        ax1[2, 0].get_xaxis().set_ticks([])
        ax1[2, 0].get_yaxis().set_ticks([])
        ax1[2, 0].set_title("L1-Map1ReLUPool")

        ax1[2, 1].imshow(l1_feature_map_relu_pool[:, : , 1]).set_cmap("gray")
        ax1[2, 0].get_xaxis().set_ticks([])
        ax1[2, 0].get_yaxis().set_ticks([])
        ax1[2, 1].set_title("L1-Map2ReLUPool")

        matplotlib.pyplot.savefig("L1.png", bbox_inches = "tight")
        matplotlib.pyplot.close(fig1)

       // Layer 2
        fig2, ax2 = matplotlib.pyplot.subplots(nrows = 3, ncols = 3)
        ax2[0, 0].imshow(l2_feature_map[:, : , 0]).set_cmap("gray")
        ax2[0, 0].get_xaxis().set_ticks([])
        ax2[0, 0].get_yaxis().set_ticks([])
        ax2[0, 0].set_title("L2-Map1")

        ax2[0, 1].imshow(l2_feature_map[:, : , 1]).set_cmap("gray")
        ax2[0, 1].get_xaxis().set_ticks([])
        ax2[0, 1].get_yaxis().set_ticks([])
        ax2[0, 1].set_title("L2-Map2")

        ax2[0, 2].imshow(l2_feature_map[:, : , 2]).set_cmap("gray")
        ax2[0, 2].get_xaxis().set_ticks([])
        ax2[0, 2].get_yaxis().set_ticks([])
        ax2[0, 2].set_title("L2-Map3")

        ax2[1, 0].imshow(l2_feature_map_relu[:, : , 0]).set_cmap("gray")
        ax2[1, 0].get_xaxis().set_ticks([])
        ax2[1, 0].get_yaxis().set_ticks([])
        ax2[1, 0].set_title("L2-Map1ReLU")

        ax2[1, 1].imshow(l2_feature_map_relu[:, : , 1]).set_cmap("gray")
        ax2[1, 1].get_xaxis().set_ticks([])
        ax2[1, 1].get_yaxis().set_ticks([])
        ax2[1, 1].set_title("L2-Map2ReLU")

        ax2[1, 2].imshow(l2_feature_map_relu[:, : , 2]).set_cmap("gray")
        ax2[1, 2].get_xaxis().set_ticks([])
        ax2[1, 2].get_yaxis().set_ticks([])
        ax2[1, 2].set_title("L2-Map3ReLU")

        ax2[2, 0].imshow(l2_feature_map_relu_pool[:, : , 0]).set_cmap("gray")
        ax2[2, 0].get_xaxis().set_ticks([])
        ax2[2, 0].get_yaxis().set_ticks([])
        ax2[2, 0].set_title("L2-Map1ReLUPool")

        ax2[2, 1].imshow(l2_feature_map_relu_pool[:, : , 1]).set_cmap("gray")
        ax2[2, 1].get_xaxis().set_ticks([])
        ax2[2, 1].get_yaxis().set_ticks([])
        ax2[2, 1].set_title("L2-Map2ReLUPool")

        ax2[2, 2].imshow(l2_feature_map_relu_pool[:, : , 2]).set_cmap("gray")
        ax2[2, 2].get_xaxis().set_ticks([])
        ax2[2, 2].get_yaxis().set_ticks([])
        ax2[2, 2].set_title("L2-Map3ReLUPool")

        matplotlib.pyplot.savefig("L2.png", bbox_inches = "tight")
        matplotlib.pyplot.close(fig2)

        // Layer 3
        fig3, ax3 = matplotlib.pyplot.subplots(nrows = 1, ncols = 3)
        ax3[0].imshow(l3_feature_map[:, : , 0]).set_cmap("gray")
        ax3[0].get_xaxis().set_ticks([])
        ax3[0].get_yaxis().set_ticks([])
        ax3[0].set_title("L3-Map1")

        ax3[1].imshow(l3_feature_map_relu[:, : , 0]).set_cmap("gray")
        ax3[1].get_xaxis().set_ticks([])
        ax3[1].get_yaxis().set_ticks([])
        ax3[1].set_title("L3-Map1ReLU")

        ax3[2].imshow(l3_feature_map_relu_pool[:, : , 0]).set_cmap("gray")
        ax3[2].get_xaxis().set_ticks([])
        ax3[2].get_yaxis().set_ticks([])
        ax3[2].set_title("L3-Map1ReLUPool")

        matplotlib.pyplot.savefig("L3.png", bbox_inches = "tight")
        matplotlib.pyplot.close(fig3)
}








