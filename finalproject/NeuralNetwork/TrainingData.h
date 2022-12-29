#pragma once
#include	<iostream>
#include	<string>
#include	<vector>
#include <fstream>
using namespace std;

class TrainingData
{
public:
	TrainingData(const string filename);
	bool isEof(void)
	{
		return m_trainingDataFile.eof();
	}
	void getTopology(vector<unsigned>& topology);

	// Returns the number of input values read from the file:
	unsigned getNextInputs(vector<double>& inputVals);
	unsigned getTargetOutputs(vector<double>& targetOutputVals);

private:
	ifstream m_trainingDataFile;
};