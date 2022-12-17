#pragma once
#include "AveragePooling2D.h"

class Flatten
{
public:
	Flatten(AveragePooling2D previous_layer);
private:
	AveragePooling2D previous_layer;
};

