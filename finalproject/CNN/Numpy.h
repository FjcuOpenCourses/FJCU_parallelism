#pragma once
class Numpy
    {
    public:

        static vector<float> zeros(int Size1);
        static vector<vector<float>> zeros(int Size1, int Size2);
        static vector<vector<vector<float>>> zeros(int Size1, int Size2, int Size3);

        static vector<int> arange(int start,int end,int stept);
        static vector<float> arange(float end, float stept); 

        static vector<float> Ceil(vector<float> input);
        static vector<vector<float>> Ceil(vector<vector<float>> input);


        static vector<float> Floor(vector<float> input);
        static vector<vector<float>> Floor(vector<vector<float>> input);


        static vector<float> Max(vector<float> input, int value);
        static vector<vector<float>> Max(vector<vector<float>> input, int value);
        static vector<vector<vector<float>>> Max(vector<vector<vector<float>>> input, int value);

        static int  sum(vector<float> input);
        static int  sum(vector<vector<float>> input);
        static int  sum(vector<vector<vector<float>>>  input);


        static vector<float> Rand(size_t Size1);
        static vector<vector<float>> Rand(int Size1,int Size2);
        static vector<vector<vector<float>>> Rand(int Size1, int Size2,int Size3);
        static vector<vector<vector<vector<float>>>> Rand(int Size1, int Size2, int Size3,int Size4);


        static vector<int> shape(vector<float> value);
        static vector<int> shape(vector<vector<float>> value);
        static vector<int> shape(vector<vector<vector<float>>> value);

        static  int shape(vector<float> value,int dimension);
        static  int shape(vector<vector<float>> value, int dimension);
        static  int shape(vector<vector<vector<float>>> value, int dimension);

        static int shape_num(vector<float> value);
        static int shape_num(vector<vector<float>> value);
        static int shape_num(vector<vector<vector<float>>> value);

        static vector<int> uint16(vector<float> value);
        static vector<vector<int>> uint16(vector<vector<float>> value);
        static vector<vector<vector<int>>> uint16(vector<vector<vector<float>>> value);
};