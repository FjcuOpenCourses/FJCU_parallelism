#include	"Model.h"
#include	"Dense.h"
using namespace std;

Model::Model(Dense *last_layer, int epochs, double learning_rate) {
	this->last_layer = last_layer;
	this->epochs = epochs;
	this->learning_rate = learning_rate;
}
void Model::setLast_layer(Dense *last_layer) {
	this->last_layer = last_layer;
}