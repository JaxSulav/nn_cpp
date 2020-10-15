#include "../include/NeuralNetwork.h"



NeuralNetwork::NeuralNetwork(std::vector<int> topology, std::vector<double> inputVals) 
{
    /* topology vector stores the values of number of neurons in each layer as index of the layers. 
    If the nn contains 3 input layers, 2 hidden and 2 output layer, topology vector contains (3,2,2) */
    this->topology = topology;
    this->inputVals = inputVals;

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

    // Set inputs value of the inputVals vector to the neurons of the input layer of neural network
    for (int i=0; i<(int)this->layers.at(0)->getNeuronsofALayer().size(); i++){
        this->layers.at(0)->getNeuronsofALayer().at(i)->setNeuronVal(this->inputVals.at(i));
    }
    
}


NeuralNetwork::~NeuralNetwork() 
{
    delete l;
}


void NeuralNetwork::feedForward() 
{
    for (int i=1; i<(int)this->layers.size(); i++){
        // For each layer, starting from 2nd layer
        for (int j=0; j<(int)this->layers.at(i)->getNeuronsofALayer().size(); j++){
            // For each neuron
            double perceptronOutput = 0.00;
            for (int k=0; k<(int)this->layers.at(i-1)->getNeuronsofALayer().size(); k++){
                // For each previous neuron
                double prevNeuronVal;

                /* The activated value of a neuron will be the input for the neurons in next layer */ 
                // So, take the previous neuron value only if it is the first hidden layer else, take the activated value of previous neuron as input for next layers
                if (i == 1){
                    prevNeuronVal = this->layers.at(i-1)->getNeuronsofALayer().at(k)->getNeuronVal();
                }else{
                    prevNeuronVal = this->layers.at(i-1)->getNeuronsofALayer().at(k)->getActivatedVal();
                }
                double prevNeuronWeight = this->layers.at(i-1)->getNeuronsofALayer().at(k)->getNeuronWeights().at(j);
                double product = prevNeuronVal * prevNeuronWeight;
                perceptronOutput += product;
            }
            
            // Set the perceptron output value to the neuron
            this->layers.at(i)->getNeuronsofALayer().at(j)->setNeuronVal(perceptronOutput);

            // Activate the perceptron output and set the activated value to the neuron's activationVal
            double activatedPerceptronOp = Activate::ACTIVATION_SIGMOID(perceptronOutput);
            this->layers.at(i)->getNeuronsofALayer().at(j)->setActivatedVal(activatedPerceptronOp);

        }
    }
}


void NeuralNetwork::printLayers() 
{
    // Log
    for (int i=0; i<(int)layers.size(); i++){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Layer: " << i << " : " << this->layers.at(i) << std::endl;
        for (int j=0; j<(int)this->layers.at(i)->getNeuronsofALayer().size(); j++){
            if (i == 0){
                std::cout << "Neuron val at neuron " << j << " : " << this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronVal() << std::endl;
            }else{
                std::cout << "Neuron activated val at neuron " << j << " : " << this->layers.at(i)->getNeuronsofALayer().at(j)->getActivatedVal() << std::endl;
            }
            for (int k=0; k<(int)this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronWeights().size(); k++){
                std::cout << "Neuron weights at neuron " << j << " : " << k << " : " << this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronWeights().at(k) << std::endl;
            }
        }

    }
}
