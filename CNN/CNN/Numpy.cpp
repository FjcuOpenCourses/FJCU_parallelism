#include "Numpy.h"
#include <iostream>
#include <cmath>
#include <omp.h>
// MathLibrary.cpp
// compile with: cl /c /EHsc MathLibrary.cpp
// post-build command: lib MathLibrary.obj

using namespace std;

namespace MathLibrary
{
    vector<vector<float>> Numpy:: zeros(vector<vector<float>> input)
    {
        int ROW_COUNT = input.size();
        int COLUMN_COUNT = input[0].size();

        vector<vector<float>> result(ROW_COUNT,vector<float>(COLUMN_COUNT));
        return result;
    }

    vector<vector<float>>  Numpy:: arange(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());

        return result;
    }

    vector<vector<float>>  Numpy:: Ceil(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Ceil(input[i]);
        }
#pragma omp barrier
        return result;
    }

    vector<float> Numpy::Ceil(vector<float> input) {
        vector <float> result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = ceil(input[i]);
        }
#pragma omp barrier
        return result;
    }

    vector<vector<float>>  Numpy::Floor(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Floor(input[i]);
        }
#pragma omp barrier
        return result;
    }

    vector<float>  Numpy::Floor(vector<float> input) {
        vector<float>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size();i++) {
            result[i] = floor(input[i]);
        }
#pragma omp barrier
        return result;
    }

    vector<vector<float>> Numpy::Max(vector<vector<float>> input, int value) {
        vector<vector<float>>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
                result[i]  = Max(input[i], value);
        }
#pragma omp barrier
        return result;
    }

    vector<float>  Numpy::Max(vector<float> input, int value) {
        vector<float>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            if (input[i] >= value) {
                result[i] = input[i];
            }
            else {
                result[i] = value;
            }
        }
#pragma omp barrier
        return result;
    }
}