#pragma once
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<cstdio>
using namespace std;

class Numpy
{
public:

    static vector<double> zeros(int Size1);
    static vector<vector<double>> zeros(int Size1, int Size2);
    static vector<vector<vector<double>>> zeros(int Size1, int Size2, int Size3);

    static vector<int> arange(int start, int end, int stept);

    static vector<double> Ceil(vector<double> input);
    static vector<vector<double>> Ceil(vector<vector<double>> input);


    static vector<double> Floor(vector<double> input);
    static vector<vector<double>> Floor(vector<vector<double>> input);


    static vector<double> Max(vector<double> input, int value);
    static vector<vector<double>> Max(vector<vector<double>> input, int value);
    static vector<vector<vector<double>>> Max(vector<vector<vector<double>>> input, int value);

    static int  sum(vector<double> input);
    static int  sum(vector<vector<double>> input);
    static int  sum(vector<vector<vector<double>>>  input);


    static vector<double> Rand(int Size1);
    static vector<vector<double>> Rand(int Size1, int Size2);
    static vector<vector<vector<double>>> Rand(int Size1, int Size2, int Size3);
    static vector<vector<vector<vector<double>>>> Rand(int Size1, int Size2, int Size3, int Size4);


    static vector<int> shape(vector<double> value);
    static vector<int> shape(vector<vector<double>> value);
    static vector<int> shape(vector<vector<vector<double>>> value);

    static  int shape(vector<double> value, int dimension);
    static  int shape(vector<vector<double>> value, int dimension);
    static  int shape(vector<vector<vector<double>>> value, int dimension);

    static int shape_num(vector<double> value);
    static int shape_num(vector<vector<double>> value);
    static int shape_num(vector<vector<vector<double>>> value);
};
