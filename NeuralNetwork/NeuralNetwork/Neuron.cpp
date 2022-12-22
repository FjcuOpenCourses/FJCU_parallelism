#include	<iostream>
#include	"Layer.h"
#include	"Neuron.h"
using namespace std;

double Neuron::eta = 0.15; // overall net learning rate
double Neuron::alpha = 0.5; // momentum, multiplier of last deltaWeight, [0.0..n]

void Neuron::updateInputWeights(Layer& prevLayer)
{
	// The weights to be updated are in the Connection container
	// in the nuerons in the preceding layer

	for (unsigned n = 0; n < prevLayer.size(); ++n)
	{
		Neuron& neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight =
			// Individual input, magnified by the gradient and train rate:
			eta
			* neuron.getOutputVal()
			* m_gradient
			// Also add momentum = a fraction of the previous delta weight
			+ alpha
			* oldDeltaWeight;
		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}
double Neuron::sumDOW(const Layer& nextLayer) const
{
	double sum = 0.0;

	// Sum our contributions of the errors at the nodes we feed
//#pragma omp parallel for reduction(+:sum)
	for (unsigned n = 0; n < nextLayer.size() - 1; ++n)
	{
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}

void Neuron::calcHiddenGradients(const Layer& nextLayer)
{
	double dow = sumDOW(nextLayer);
	m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
}
void Neuron::calcOutputGradients(double targetVals)
{
	double delta = targetVals - m_outputVal;
	m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);
}

double Neuron::transferFunction(double x)
{
	// tanh - output range [-1.0..1.0]
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
	// tanh derivative
	return 1.0 - x * x;
}

void Neuron::feedForward(const Layer& prevLayer)
{
	double sum = 0.0;

	// Sum the previous layer's outputs (which are our inputs)
	// Include the bias node from the previous layer.
	for (unsigned n = 0; n < prevLayer.size(); ++n)
	{
		sum += prevLayer[n].getOutputVal() *
			prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	for (unsigned c = 0; c < numOutputs; ++c) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}

	m_myIndex = myIndex;
}