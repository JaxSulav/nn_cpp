#include "../include/Layer.h"


Layer::Layer(int size) 
{
   this->size = size; 

   // Initialize neurons for each layer with zero value and store them in neurons vector
   for (int i=0; i<this->size; i++){
      this->n = new Neuron(0.00);
      neurons.push_back(this->n);
   }
}


Layer::~Layer() 
{
   delete n;
}


// Setter
void Layer::setNeuronWeights(int numWeights, int neuronIdx) 
{
   // Set the number of weights for the neuron, which is the number of neurons in the next layer 
   this->neurons.at(neuronIdx)->setNumWeights(numWeights);

   // Set every weight values for each neuron
   for (int j=0; j<numWeights; j++){
      // For each weight values
      this->neurons.at(neuronIdx)->setWeights(rand_generator::rand_gen_norm_dist());
   }
}
