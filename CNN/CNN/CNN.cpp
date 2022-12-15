#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <vector>

using namespace std;

vector<vector<int>> conv_(vector<vector<float>> img, vector<vector<float>> conv_filter)
{
	vector<vector<int>> b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i].push_back(0);
		}
	}
}

vector<vector<int>> conv(vector<vector<float>> img, vector<vector<float>> conv_filter)
{

}

vector<vector<vector<int>>> pooling(vector<vector<vector<float>>> feature_map, int size = 2, int stride = 2)
{

}

vector<vector<vector<int>>> relu(vector<vector<vector<float>>> feature_map)
{

}

int main()
{
	std::cout << "Hello World!\n";
}