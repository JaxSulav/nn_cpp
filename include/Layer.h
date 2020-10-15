#pragma once

#include <iostream>
#include <vector>

#include "Neuron.h"

class Layer
{
public:
    Layer(int size);
    ~Layer();

public:
    std::vector<Neuron *> getNeuronsofALayer() {return this->neurons;}

private:
    int size;
    std::vector<Neuron *> neurons;

private:
    // Heap allocated
    Neuron *n;
};
