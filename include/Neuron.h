#pragma once

#include <iostream>


class Neuron
{
public:
    Neuron(double neuronVal);
    ~Neuron();

public:
    // Getters
    double getNeuronVal() {return this->neuronVal;}

private:
    double neuronVal;
    double neuronActivatedVal;

};