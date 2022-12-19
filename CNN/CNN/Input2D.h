#pragma once
#include <iostream>
#include<vector>
class BaseLayer;
using namespace std;
class Input2D :public BaseLayer
{
public:
	Input2D(vector<int> inputShape);
private:
	vector<int> input_shape;
};
