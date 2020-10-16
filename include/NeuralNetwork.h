#pragma once

#include <iostream>
#include <vector>

#include "Layer.h"
#include "../include/Activation.h"

class NeuralNetwork
{
public:
    NeuralNetwork(std::vector<int> topology, std::vector<double> inputVals, std::vector<double> expectedOutputs);
    ~NeuralNetwork();

public:
    void feedForward();

    void calcErrors();

    void backwardPropagation();

    void printLayers();

    void train(int iteration);

private:
    std::vector<int> topology;
    std::vector<double> errors;
    std::vector<Layer *> layers;
    std::vector<double> inputVals;
    std::vector<double> expectedOutputs;

private:
    // Heap allocated
    Layer *l;

};