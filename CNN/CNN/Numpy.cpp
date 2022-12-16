#include "Numpy.h"
#include <iostream>
#include <cmath>
#include <omp.h>
// MathLibrary.cpp
// compile with: cl /c /EHsc MathLibrary.cpp
// post-build command: lib MathLibrary.obj

using namespace std;

class Numpy
{
public:
    static vector<vector<float>>  zeros(vector<vector<float>> input)
    {
        int ROW_COUNT = input.size();
        int COLUMN_COUNT = input[0].size();

        vector<vector<float>> result(ROW_COUNT, vector<float>(COLUMN_COUNT));
        return result;
    }

    static vector<vector<float>> arange(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());

        return result;
    }

    static vector<vector<float>>  Ceil(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Ceil(input[i]);
        }
#pragma omp barrier
        return result;
    }

    static vector<float> Ceil(vector<float> input) {
        vector <float> result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = ceil(input[i]);
        }
#pragma omp barrier
        return result;
    }

    static vector<vector<float>> Floor(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Floor(input[i]);
        }
#pragma omp barrier
        return result;
    }

    static vector<float> Floor(vector<float> input) {
        vector<float>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = floor(input[i]);
        }
#pragma omp barrier
        return result;
    }

    static vector<vector<float>> Max(vector<vector<float>> input, int value) {
        vector<vector<float>>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Max(input[i], value);
        }
#pragma omp barrier
        return result;
    }
    static vector<vector<vector<float>>> Max(vector<vector<vector<float>>> input, int value) {
        vector<vector<vector<float>>>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Max(input[i], value);
        }
#pragma omp barrier
        return result;
    }

    static vector<float>  Max(vector<float> input, int value) {
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
};