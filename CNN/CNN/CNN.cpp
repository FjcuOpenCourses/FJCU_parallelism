#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include "Numpy.h"
#include <cmath>

using namespace std;

using namespace MathLibrary;

vector<vector<float>> conv_(vector<vector<float>> img, vector<vector<float>> conv_filter)
{
	vector<vector<float>> conv_result;

	vector<vector<int>> b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i].push_back(0);
		}
	}
	return conv_result;
}

vector<vector<float>> conv(vector<vector<float>> img, vector<vector<float>> conv_filter)
{
	vector<vector<float>> convresult;

	return convresult;
}

vector<vector<vector<float>>> pooling(vector<vector<vector<float>>> feature_map, int size = 2, int stride = 2)
{
	vector<vector<vector<float>>> poolingresult;

	return poolingresult;
}

vector<vector<vector<float>>> relu(vector<vector<vector<float>>> feature_map)
{
	vector<vector<vector<float>>> reluresult;

	return reluresult;
}

int main()
{
	
}