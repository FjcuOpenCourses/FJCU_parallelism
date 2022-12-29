#include "Numpy.h"
#include <iostream>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

vector<double> Numpy::zeros(int Size1) {
    vector<double> result(Size1);
    return result;
}
vector<vector<double>> Numpy::zeros(int Size1, int Size2) {
    vector<vector<double>> result(Size1,vector<double>(Size2, 0));
//#pragma omp parallel for
//    for (int i = 0; i < result.size(); i++) {
//        result[i] = Numpy::zeros(Size2);
//    }
    return result;
}
vector<vector<vector<double>>> Numpy::zeros(int Size1, int Size2, int Size3) {
    vector<vector<vector<double>>> result(Size1);
#pragma omp parallel for
    for (int i = 0; i < result.size(); i++) {
        result[i] = Numpy::zeros(Size2, Size3);
    }
    return result;
}

vector<int> Numpy::arange(int start, int end, int stept) {
    vector<int> result;
    for (int i = start; i < end; i += stept) {
        result.push_back(i);
    }
    return result;
}

//vector<double> Numpy::arange(double start, double end, double stept) {
//    vector<double> result;
//    for (int i = start; i < end; i += stept) {
//        result.push_back(i);
//    }
//    return result;
//}

vector<vector<double>>  Numpy::Ceil(vector<vector<double>> input) {
    vector <vector<double>> result(input.size());
#pragma omp parallel for
    for (int i = 0; i < input.size(); i++) {
        result[i] = Ceil(input[i]);
    }
    return result;
}

vector<double> Numpy::Ceil(vector<double> input) {
    vector <double> result(input.size());
#pragma omp parallel for
    for (int i = 0; i < input.size(); i++) {
        result[i] = ceil(input[i]);
    }
    return result;
}

vector<vector<double>> Numpy::Floor(vector<vector<double>> input) {
    vector <vector<double>> result(input.size());
#pragma omp parallel for
    for (int i = 0; i < input.size(); i++) {
        result[i] = Floor(input[i]);
    }
    return result;
}

vector<double> Numpy::Floor(vector<double> input) {
    vector<double>result(input.size());
#pragma omp parallel for
    for (int i = 0; i < input.size(); i++) {
        result[i] = floor(input[i]);
    }
    return result;
}

vector<vector<double>> Numpy::Max(vector<vector<double>> input, int value) {
    vector<vector<double>>result(input.size());
#pragma omp parallel for
    for (int i = 0; i < input.size(); i++) {
        result[i] = Max(input[i], value);
    }
    return result;
}
vector<vector<vector<double>>> Numpy::Max(vector<vector<vector<double>>> input, int value) {
    vector<vector<vector<double>>>result(input.size());
#pragma omp parallel for
    for (int i = 0; i < input.size(); i++) {
        result[i] = Max(input[i], value);
    }
    return result;
}

vector<double>  Numpy::Max(vector<double> input, int value) {
    vector<double>result(input.size());
#pragma omp parallel for
    for (int i = 0; i < input.size(); i++) {
        result[i] = (input[i] >= value ? input[i] : value);
    }
    return result;
}
vector<double> Numpy::Rand(int Size1)
{
    vector<double>data(Size1);
#pragma omp parallel for
    for (int i = 0; i < data.size(); i++) {
        data[i] = rand() / double(RAND_MAX);
    }
    return data;
}
vector<vector<double>> Numpy::Rand(int Size1, int Size2) {
    vector<vector<double>> result(Size1);
#pragma omp parallel for
    for (int i = 0; i < result.size(); i++) {
        result[i] = Rand(Size2);
    }
    return result;
}
vector<vector<vector<double>>> Numpy::Rand(int Size1, int Size2, int Size3) {
    vector<vector<vector<double>>> result(Size1);
#pragma omp parallel for
    for (int i = 0; i < result.size(); i++) {
        result[i] = Rand(Size2, Size3);
    }
    return result;
}
vector<vector<vector<vector<double>>>> Numpy::Rand(int Size1, int Size2, int Size3, int Size4) {
    vector<vector<vector<vector<double>>>> result(Size1);
#pragma omp parallel for
    for (int i = 0; i < result.size(); i++) {
        result[i] = Rand(Size2, Size3, Size3);
    }
#pragma omp barrier
    return result;
}

vector<int>Numpy::shape(vector<double> value) {
    vector<int>result;
    result.push_back(value.size());
    return result;
}
vector<int> Numpy::shape(vector<vector<double>> value) {
    vector<int>result;
    result.push_back(value.size());
    result.push_back(value[0].size());
    return result;
}
vector<int> Numpy::shape(vector<vector<vector<double>>> value) {
    vector<int>result;
    result.push_back(value.size());
    result.push_back(value[0].size());
    result.push_back(value[0][0].size());
    return result;
}

int Numpy::shape_num(vector<double> value) {
    vector<int>result = shape(value);
    return result.size();
}
int Numpy::shape_num(vector<vector<double>> value) {
    vector<int>result = shape(value);
    return result.size();
}

int Numpy::shape(vector<double> value, int dimension) {
    vector<int>shape_value = shape(value);
    return shape_value[dimension];
}
int Numpy::shape(vector<vector<double>> value, int dimension) {
    vector<int>shape_value = shape(value);
    return shape_value[dimension];
}
int Numpy::shape(vector<vector<vector<double>>> value, int dimension) {
    vector<int>shape_value = shape(value);
    return shape_value[dimension];
}