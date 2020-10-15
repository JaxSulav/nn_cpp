#pragma once

#include <iostream>
#include <vector>

#include "Layer.h"

class NeuralNetwork
{
public:
    NeuralNetwork(std::vector<int> topology, std::vector<double> inputVals);
    ~NeuralNetwork();

private:
    std::vector<int> topology;
    std::vector<Layer *> layers;
    std::vector<double> inputVals;

private:
    // Heap allocated
    Layer *l;

};