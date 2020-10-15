#include<iostream>

#include "../include/NeuralNetwork.h"

int main(int argc, char const *argv[])
{
    std::vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    NeuralNetwork *nn = new NeuralNetwork(topology);
    return 0;
}
