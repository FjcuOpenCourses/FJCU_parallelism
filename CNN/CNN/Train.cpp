#include    "Sigmoid.h"
#include    "Input2D.h"
#include    "Conv2D.h"
#include    "AveragePooling2D.h"
#include    "MaxPooling2D.h"
#include    "Flatten.h"
#include    "Dense.h"
#include    "Model.h"


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

    Flatten flatten_layer(previous_layer = pooling_layer)
    Dense dense_layer1(num_neurons = 100,
            previous_layer = flatten_layer,
            activation_function = "relu")
        dense_layer2 = pygad.cnn.Dense(num_neurons = num_classes,
            previous_layer = dense_layer1,
            activation_function = "softmax")

        model = pygad.cnn.Model(last_layer = dense_layer2,
            epochs = 1,
            learning_rate = 0.01)

        model.summary()

        model.train(train_inputs = train_inputs,
            train_outputs = train_outputs)

        predictions = model.predict(data_inputs = train_inputs)
        print(predictions)

        num_wrong = numpy.where(predictions != train_outputs)[0]
        num_correct = train_outputs.size - num_wrong.size
        accuracy = 100 * (num_correct / train_outputs.size)
        print("Number of correct classifications : {num_correct}.".format(num_correct = num_correct))
        print("Number of wrong classifications : {num_wrong}.".format(num_wrong = num_wrong.size))
        print("Classification accuracy : {accuracy}.".format(accuracy = accuracy))
	return 0;
}