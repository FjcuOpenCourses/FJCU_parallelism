#include    "Sigmoid.h"
#include    "Input2D.h"
#include    "Conv2D.h"
#include    "AveragePooling2D.h"
#include    "MaxPooling2D.h"
#include    "Flatten.h"
#include    "Dense.h"
#include    "Model.h"
#include <iostream>

using namespace std;

int main() {
	int num_classes = 4;
    Input2D             input_layer(sample_shape);
    Conv2D              conv_layer1(2, 3, input_layer, NULL);
    Sigmoid             relu_layer1(conv_layer1);
    AveragePooling2D    average_pooling_layer(2, relu_layer1, 2);
    Conv2D              conv_layer2(3, 3, average_pooling_layer, NULL);
    ReLU                relu_layer2(conv_layer2);
    MaxPooling2D        max_pooling_layer(2, relu_layer2, 2);
    Conv2D              conv_layer3(1, 3, max_pooling_layer, NULL);
    ReLU                relu_layer3(conv_layer3);
    AveragePooling2D    pooling_layer(2, relu_layer3, 2);
    Flatten             flatten_layer(pooling_layer);
    Dense               dense_layer1(100,flatten_layer,"relu");
    Dense               dense_layer2(num_classes, dense_layer1,"softmax");
    Model               model(dense_layer2, 1, 0.01);
    model.summary();
    model.train(train_inputs = train_inputs, train_outputs = train_outputs);
    predictions = model.predict(data_inputs = train_inputs);
    print(predictions);
    int num_wrong = numpy.where(predictions != train_outputs)[0];
        int num_correct = train_outputs.size - num_wrong.size;
    int accuracy = 100 * (num_correct / train_outputs.size);
    printf("Number of correct classifications : {%d}.", num_correct);
    printf("Number of wrong classifications : {%d}.",num_wrong.size);
    printf("Classification accuracy : {%.l2f}.",accuracy);
	return 0;
}