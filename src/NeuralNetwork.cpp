#include "../include/NeuralNetwork.h"



NeuralNetwork::NeuralNetwork(std::vector<int> topology) 
{
    /* topology vector stores the values of number of neurons in each layer as index of the layers. If the nn contains 3 input layers, 2 hidden and 2 output layer, topology vector contains (3,2,2) */

    this->topology = topology;

    for (int i=0; i<topology.size(); i++){
        this->l = new Layer(topology.at(i));
        this->layers.push_back(this->l);
    }

    for (int i=0; i<layers.size(); i++){
        std::cout << "Layer: " << i << " : " << this->layers.at(i) << std::endl;
        for (int j=0; j<this->layers.at(i)->getNeuronsofALayer().size(); j++){
            std::cout << "Neuron: " << j << " : " << this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronVal() << std::endl;
        }

    }
    
}


NeuralNetwork::~NeuralNetwork() 
{
    delete l;
}
