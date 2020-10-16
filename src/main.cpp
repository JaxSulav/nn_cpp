#include<iostream>

#include "../include/NeuralNetwork.h"

int main(int argc, char const *argv[])
{
    // Topology of the neural network
    std::vector<int> topology;
    topology.push_back(3); // Input Layer
    topology.push_back(2); // Hidden Layer
    topology.push_back(3); // Ouptut Layer

    std::vector<double> input;
    input.push_back(0);
    input.push_back(1);
    input.push_back(2);

    std::vector<double> output;
    output.push_back(0);
    output.push_back(1);
    output.push_back(2);

    // Create new instance of neural network
    NeuralNetwork *nn = new NeuralNetwork(topology, input, output);
    nn->feedForward();
    nn->printLayers();
    nn->backwardPropagation();
    std::cout << "_____----------__________--------__________----\n" << std::endl;
    nn->printLayers();
    nn->feedForward();
    std::cout << "_____----------__________--------__________----\n" << std::endl;
    nn->printLayers();


    delete nn;
    return 0;
}
