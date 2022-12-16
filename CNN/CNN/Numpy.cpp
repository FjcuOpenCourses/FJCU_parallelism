#include "Numpy.h"
#include <iostream>
#include <cmath>
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
    
    }
    vector<vector<float>>  Numpy:: ceil(vector<vector<float>> input) {
    
    }
    vector<vector<float>>  Numpy::floor(vector<vector<float>> input) {
        vector <vector<float>> result(input.size());
        for (int i = 0; i < input.size(); i++) {
            result.assign(i, floor(input[i]));
           
        }
        return result;
    }
    vector<float>  Numpy::floor(vector<float> input) {
        vector<float>result(input.size());
        for (int i = 0; i < input.size();i++) {
            result[i] = floor(input[i]);
        }
        return result;
    }
    static vector<vector<float>> Numpy::max(vector<vector<float>> input, int value) {
            
    }

}