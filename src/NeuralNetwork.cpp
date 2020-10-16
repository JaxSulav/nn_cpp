#include "../include/NeuralNetwork.h"



NeuralNetwork::NeuralNetwork(std::vector<int> topology, std::vector<double> inputVals, std::vector<double> expectedOutputs) 
{
    if (topology.size() == 0 || inputVals.size() == 0 || expectedOutputs.size() == 0){
        std::cerr << "Empty topology or inputs or outputs" << std::endl;
        std::abort();
    }

    /* topology vector stores the values of number of neurons in each layer as index of the layers. 
    If the nn contains 3 input layers, 2 hidden and 2 output layer, topology vector contains (3,2,2) */
    this->topology = topology;
    this->inputVals = inputVals;
    this->expectedOutputs = expectedOutputs;

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

            // Find and set the derivative value for the activated Val of neuron
            double derivedActivatedVal = Derive::DERIVATION_SIGMOID(activatedPerceptronOp);
            this->layers.at(i)->getNeuronsofALayer().at(j)->setDerivedVal(derivedActivatedVal);

        }
    }
}


void NeuralNetwork::calcErrors() 
{
    /* Here we calculate the error, just by subtracting the activated result of output neuron 
    from the expected output and do not take the MSE because we perform the derivative of 
    the MSE in the backpropagation algorithm which will result in the negative of the following calculated error */

    int outputLayerIdx = this->layers.size() - 1 ;
    // For each neuron in output layer
    for (int i=0; i<(int)this->layers.at(outputLayerIdx)->getNeuronsofALayer().size(); i++){

        // The output vector size should match the number of output neurons
        if (this->expectedOutputs.size() != this->layers.at(outputLayerIdx)->getNeuronsofALayer().size()){
            std::cerr << "Number of outputs doesn't match the number of neuron in output layer" << std::endl;
            std::abort();
        }
        
        double error = this->expectedOutputs.at(i) - this->layers.at(outputLayerIdx)->getNeuronsofALayer().at(i)->getActivatedVal();
        errors.push_back(error);

    }
}


void NeuralNetwork::backwardPropagation() 
{
    double learningRate = 1;

    // Calculate errors
    this->calcErrors();

    for (int i=0; i<errors.size(); i++){
        std::cout << "ERRORS: " << errors.at(i) << std::endl;
    }

    std::vector<Neuron *> lastHiddenLayerNeurons = this->layers.at(this->layers.size()-2)->getNeuronsofALayer();
    std::vector<Neuron *> outputNeurons = this->layers.at(this->layers.size()-1)->getNeuronsofALayer();

    // Weights update for last hidden layer
    for (int i=0; i<lastHiddenLayerNeurons.size(); i++){
        // For each neurons in last hidden layer
        for (int j=0; j<(int)outputNeurons.size(); j++){
            // For each weight of a neuron
            
            /* dE/dA -> Error w.r.t the activation function */
            double A = - (errors.at(j));
            /* dA/dZ -> Activation function w.r.t the summed weight of the perceptron i.e the neuronVal of this neuron */
            double B = outputNeurons.at(j)->getDerivedVal();
            /* dZ/dW -> Neuron value w.r.t the weight */
            double C = lastHiddenLayerNeurons.at(i)->getActivatedVal();

            /* THE CHAIN RULE  (dE/dW) */
            double gradient = A * B * C;
            
            double oldWeight = lastHiddenLayerNeurons.at(i)->getNeuronWeights().at(j);

            // Since, new weight  = old weight + (learning lare * (-gradient))
            double updatedWeight = oldWeight - ( learningRate * gradient);
            // Set the updated weight
            lastHiddenLayerNeurons.at(i)->setWeightsAtIdx(j, updatedWeight);

        }
    }

    /*  Weights update for other layers */
    for (int i=this->layers.size()-3; i>=0; i--){
        // Incase of multiple hidden layers
        // For each layer except last hidden layer and output layer
        for (int j=0; j<(int)this->layers.at(i)->getNeuronsofALayer().size(); j++){
            // For each neuron in ith layer
            for (int k=0; k<(int)this->layers.at(i+1)->getNeuronsofALayer().size(); k++){
                // For each weight of a neuron
                double A1 = 0.00;
                double B1 = this->layers.at(i+1)->getNeuronsofALayer().at(k)->getDerivedVal(); 
                double C1;
                
                // If the layer is input layer, we simply take the neuron value because neurons at input layer does not have activated values
                // Else we take the activated value of this neuron
                if (i == 0){
                    C1 = this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronVal();
                }else{
                    C1 = this->layers.at(i)->getNeuronsofALayer().at(j)->getActivatedVal();
                }

                for (int idx=0; idx<(int)outputNeurons.size(); idx++){
                    double X = - (errors.at(idx)); 
                    double Y = this->layers.at(i+2)->getNeuronsofALayer().at(idx)->getDerivedVal(); 
                    double Z = this->layers.at(i+1)->getNeuronsofALayer().at(k)->getNeuronWeights().at(idx);

                    double productH = X * Y * Z;
                    A1 += productH;
                } 

                /* Chain Rule A1 and Backward propagation (B1 * C1) */
                double gradient1 = A1 * B1 * C1;          

                double oldWeight1 = this->layers.at(i)->getNeuronsofALayer().at(j)->getNeuronWeights().at(k);

                // Since, new weight  = old weight + (learning lare * (-gradient))
                double updatedWeight2 = oldWeight1 - (learningRate * gradient1);
                // Set the updated weight
                this->layers.at(i)->getNeuronsofALayer().at(j)->setWeightsAtIdx(k, updatedWeight2);
            }
        }
    }

    this->errors.clear();
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
