#pragma once

#include <iostream>
#include <vector>

#include "Neuron.h"
#include "Utils.h"

class Layer
{
public:
    Layer(int size);
    ~Layer();

public:
    // Getters
    std::vector<Neuron *> getNeuronsofALayer() {return this->neurons;}

    // Setters
    void setNeuronWeights(int numWeights, int neuronIdx); 

private:
    int size;
    std::vector<Neuron *> neurons;

private:
    // Heap allocated
    Neuron *n;
};
