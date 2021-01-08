#include<iostream>

#include "../include/NeuralNetwork.h"

int main(int argc, char const *argv[])
{
    int ret_cfg = parse_config("../config.cfg");
    if (ret_cfg == 1){
        std::cout << "Unable to open the config file ..." << std::endl;
    }

    // Topology of the neural network
    std::vector<int> topology;
    topology.push_back(3); // Input Layer
    topology.push_back(2); // Hidden Layer
    topology.push_back(2); // Ouptut Layer

    std::vector<double> input;
    input.push_back(0.5);
    input.push_back(0.75);
    input.push_back(0.25);

    std::vector<double> output;
    output.push_back(0.1);
    output.push_back(0.9);

    // Create new instance of neural network
    NeuralNetwork *nn = new NeuralNetwork(topology, input, output);
    nn->train(ITERATION);

    delete nn;
    return 0;
}
