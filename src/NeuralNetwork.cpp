#include "../include/NeuralNetwork.h"



NeuralNetwork::NeuralNetwork(std::vector<int> topology) 
{
    /* topology vector stores the values of number of neurons in each layer as index of the layers. 
    If the nn contains 3 input layers, 2 hidden and 2 output layer, topology vector contains (3,2,2) */
    this->topology = topology;

    // Initialize the layers for the network and store in layers vector
    for (int i=0; i<(int)topology.size(); i++){
        this->l = new Layer(topology.at(i));
        this->layers.push_back(this->l);
    }

    // Set the neuron weights for every neurons in each layer except last later i.e output layer
    for (int i=0; i<(int)this->layers.size()-1; i++){
        // For each layer except last layer
        for (int j=0; j<(int)layers.at(i)->getNeuronsofALayer().size(); j++){
            // For each neuron 
            this->layers.at(i)->setNeuronWeights(this->layers.at(i+1)->getNeuronsofALayer().size(), j);
        }
    }

    // Log
    for (int i=0; i<(int)layers.size(); i++){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Layer: " << i << " : " << this->layers.at(i) << std::endl;
        for (int j=0; j<(int)this->layers.at(i)->getNeuronsofALayer().size(); j++){
            std::cout << "Neuron val at neuron " << j << " : " << this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronVal() << std::endl;
            for (int k=0; k<(int)this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronWeights().size(); k++){
                std::cout << "Neuron weights at neuron " << j << " : " << k << " : " << this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronWeights().at(k) << std::endl;
            }
        }

    }
    
}


NeuralNetwork::~NeuralNetwork() 
{
    delete l;
}
