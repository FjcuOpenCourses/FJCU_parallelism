#include "Numpy.h"
#include <iostream>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <cmath>
#include <omp.h>
#include "Numpy.h"
// MathLibrary.cpp
// compile with: cl /c /EHsc MathLibrary.cpp
// post-build command: lib MathLibrary.obj

using namespace std;

 vector<float> Numpy::zeros(int Size1) {
     vector<float> result(Size1);
     return result;
 }
 vector<vector<float>> Numpy::zeros(int Size1, int Size2) {
     vector<vector<float>> result(Size1);
     for (int i = 0; i < result.size();i++) {
         result[i] = Numpy::zeros(Size2);
     }
     return result;
 }
 vector<vector<vector<float>>> Numpy::zeros(int Size1, int Size2, int Size3) {
     vector<vector<vector<float>>> result(Size1);
     for (int i = 0; i < result.size(); i++) {
         result[i] = Numpy::zeros(Size2,Size3);
     }
     return result;
 }

 vector<int> Numpy:: arange(int start, int end, int stept) {
        vector<int> result;
        for (int i = 0; i < end;i+=stept) {
            result.push_back(i);
        }
        return result;
}

    vector<vector<float>>  Numpy::Ceil(vector<vector<float>> input) {
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

     vector<vector<float>> Numpy::Floor(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Floor(input[i]);
        }
#pragma omp barrier
        return result;
    }

     vector<float> Numpy::Floor(vector<float> input) {
        vector<float>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = floor(input[i]);
        }
#pragma omp barrier
        return result;
    }

     vector<vector<float>> Numpy::Max(vector<vector<float>> input, int value) {
        vector<vector<float>>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Max(input[i], value);
        }
#pragma omp barrier
        return result;
    }
     vector<vector<vector<float>>> Numpy::Max(vector<vector<vector<float>>> input, int value) {
        vector<vector<vector<float>>>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = Max(input[i], value);
        }
#pragma omp barrier
        return result;
    }

    vector<float>  Numpy::Max(vector<float> input, int value) {
        vector<float>result(input.size());
#pragma omp parallel for
        for (int i = 0; i < input.size(); i++) {
            result[i] = (input[i] >= value ? input[i]:value);
        }
#pragma omp barrier
        return result;
    }
    vector<float> Numpy::Rand(size_t Size1)
    {
        using value_type = float;
        // We use static in order to instantiate the random engine
        // and the distribution once only.
        // It may provoke some thread-safety issues.
        static uniform_int_distribution<value_type> distribution(
            numeric_limits<value_type>::min(),
            numeric_limits<value_type>::max());
        static default_random_engine generator;

        vector<value_type> data(Size1);
        generate(data.begin(), data.end(), []() { return distribution(generator); });
        return data;
        //https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
    }

    vector<vector<float>> Numpy::Rand(int Size1, int Size2) {
        vector<vector<float>> result(Size1);
#pragma omp parallel for
        for (int i = 0; i < result.size(); i++) {
            result[i] = Rand(Size2);
        }
#pragma omp barrier
        return result;
    }
vector<vector<vector<float>>> Numpy::Rand(int Size1, int Size2, int Size3) {
        vector<vector<vector<float>>> result(Size1);
#pragma omp parallel for
        for (int i = 0; i < result.size(); i++) {
            result[i] = Rand(Size2,Size3);
        }
#pragma omp barrier
        return result;
}
vector<vector<vector<vector<float>>>> Numpy::Rand(int Size1, int Size2, int Size3,int Size4) {
    vector<vector<vector<vector<float>>>> result(Size1);
#pragma omp parallel for
    for (int i = 0; i < result.size(); i++) {
        result[i] = Rand(Size2, Size3,Size3);
    }
#pragma omp barrier
    return result;
}

    vector<int>Numpy::shape(vector<float> value) {
        vector<int>result;
        result.push_back(value.size());
        return result;
    }
    vector<int> Numpy::shape(vector<vector<float>> *value) {
        vector<int>result;
        result.push_back(value.size());
        result.push_back(value[0].size());
        return result;
    }
    vector<int> Numpy::shape(vector<vector<vector<float>>> value) {
        vector<int>result;
        result.push_back(value.size());
        result.push_back(value[0].size());
        result.push_back(value[0][0].size());
        return result;
    }

    int Numpy::shape_num(vector<float> value) {
        vector<int>result = shape(value);
        return result.size();
    }
    int Numpy::shape_num(vector<vector<float>> value) {
        vector<int>result = shape(value);
        return result.size();
    }    
    int Numpy::shape_num(vector<float> value) {
        vector<int>result = shape(value);
        return result.size();
    }   

    int Numpy::shape(vector<float> value, int dimension) {
        vector<int>shape_value = shape(value);
        return shape_value[dimension] ;
    }
    int Numpy::shape(vector<vector<float>> value, int dimension) {
        vector<int>shape_value = shape(value);
        return shape_value[dimension];
    }
   int Numpy::shape(vector<vector<vector<float>>> value, int dimension) {
       vector<int>shape_value = shape(value);
       return shape_value[dimension];
   }