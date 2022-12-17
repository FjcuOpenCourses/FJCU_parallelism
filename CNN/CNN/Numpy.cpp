#include "Numpy.h"
#include <iostream>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
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
            result[i] = (input[i] >= value ? input[i]:value);
        }
#pragma omp barrier
        return result;
    }

    static vector<float> Rand(int Size1) {


        srand(unsigned(time(nullptr)));
        vector<int> v(Size1);
        std::generate(v.begin(), v.end(), rand);

    }
    static std::vector<float> Rand(size_t size)
    {
        using value_type = float;
        // We use static in order to instantiate the random engine
        // and the distribution once only.
        // It may provoke some thread-safety issues.
        static uniform_int_distribution<value_type> distribution(
            numeric_limits<value_type>::min(),
            numeric_limits<value_type>::max());
        static default_random_engine generator;

        vector<value_type> data(size);
        generate(data.begin(), data.end(), []() { return distribution(generator); });
        return data;
        //https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
    }

    static vector<vector<float>> Rand(int Size1, int Size2) {
        vector<vector<float>> result(Size1);
        for (int i = 0; i < result.size(); i++) {
            result[i] = Rand(Size2);
        }
    }
    static vector<vector<vector<float>>> Rand(int Size1, int Size2, int Size3) {
        vector<vector<vector<float>>> result(Size1);
        for (int i = 0; i < result.size(); i++) {
            result[i] = Rand(Size2,Size3);
        }
    }

    static int shape_num(vector<int> value) {
        vector<int>result = shape(value);
        return result.size();
    }
    static int shape_num(vector<vector<int>> value) {
        vector<int>result = shape(value);
        return result.size();
    }    
    static int shape_num(vector<int> value) {
        vector<int>result = shape(value);
        return result.size();
    }   
    static vector<int>shape(vector<int> value) {
        vector<int>result;
        result.push_back(value.size());
        return result;
    }
    static vector<int>shape(vector<vector<vector<int>>> value) {
        vector<int>result;
        result.push_back(value.size());
        result.push_back(value[0].size());
        return result;
    }
    static vector<int>shape(vector<vector<vector<int>>> value) {
        vector<int>result;
        result.push_back(value.size());
        result.push_back(value[0].size());
        result.push_back(value[0][0].size());
        return result;
    }
};