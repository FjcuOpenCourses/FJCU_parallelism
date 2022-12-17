#include	"Model.h"
#include	"Dense.h"
Model::Model(Dense last_layer, int epochs, float learning_rate) {
	this->setLast_layer(last_layer);
	this->epochs = epochs;
	this->learning_rate = learning_rate;
}
void Model::setLast_layer(Dense last_layer) {
	this->last_layer = last_layer;
}