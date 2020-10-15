#pragma once

#include <iostream>
#include <vector>

#include "Layer.h"

class NeuralNetwork
{
public:
    NeuralNetwork(std::vector<int> topology);
    ~NeuralNetwork();

private:
    std::vector<int> topology;
    std::vector<Layer *> layers;

private:
    // Heap allocated
    Layer *l;

};