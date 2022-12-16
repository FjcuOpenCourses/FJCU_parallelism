#include <vector>
#pragma once

using namespace std;

namespace MathLibrary
{
    class Numpy
    {
    public:
        static vector<vector<float>> zeros(vector<vector<float>> input);
        static vector<vector<float>> arange(vector<vector<float>> input);
        static vector<vector<float>> ceil(vector<vector<float>> input);
        static vector<float> ceil(vector<float> input);
        static vector<vector<float>> floor(vector<vector<float>> input);
        static vector<vector<float>> max(vector<vector<float>> input,int value);
        static vector<float> max(vector<float> input, int value);
    };
}