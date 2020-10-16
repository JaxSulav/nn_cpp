#pragma once

#include <iostream>
#include <vector>

#include "Utils.h"


class Neuron
{
public:
    Neuron(double neuronVal);
    ~Neuron();

public:
    // Getters
    double getNeuronVal() {return this->neuronVal;}
    double getActivatedVal() {return this->neuronActivatedVal;}
    double getDerivedVal() {return this->neuronDerivedVal;}
    std::vector<double> getNeuronWeights() {return this->weights;}

    //Setters
    void setNeuronVal(double val) {this->neuronVal = val;}
    void setActivatedVal(double val) {this->neuronActivatedVal = val;}
    void setDerivedVal(double val) {this->neuronDerivedVal = val;}
    void setWeights(double weightVal) {this->weights.push_back(weightVal);}
    void setWeightsAtIdx(int weightIdx, double val) {this->weights.at(weightIdx) = val;}
    void setNumWeights(int val) {this->numWeights = val;}

private:
    std::vector<double> weights;
    int numWeights;
    double neuronVal;
    double neuronActivatedVal;
    double neuronDerivedVal;

};