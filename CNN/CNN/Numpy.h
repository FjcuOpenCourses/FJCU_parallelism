#include <vector>
#pragma once

using namespace std;

namespace MatrixLib
{
    class Numpy
    {
    public:
        static vector<vector<int>> shape(vector<vector<float>> input);
        static vector<vector<float>> zeros(vector<vector<float>> input);
        static vector<vector<float>> arange(vector<vector<float>> input);
        static vector<vector<float>> Ceil(vector<vector<float>> input);
        static vector<float> Ceil(vector<float> input);
        static vector<vector<float>> Floor(vector<vector<float>> input);
        static vector<float> Floor(vector<float> input);
        static vector<vector<vector<float>>> Max(vector<vector<vector<float>>> input, int value);
        static vector<vector<float>> Max(vector<vector<float>> input,int value);
        static vector<float> Max(vector<float> input, int value);
        static int  sum(vector<vector<float>> input);
        static int  sum(vector<float> input);
        static vector<float> Rand(int Size1);
        static vector<vector<float>> Rand(int Size1,int Size2);
        static vector<vector<vector<float>>> Rand(int Size1, int Size2,int Size3);

    };
}