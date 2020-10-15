#include "../include/Layer.h"


Layer::Layer(int size) 
{
   this->size = size; 

   for (int i=0; i<this->size; i++){
      this->n = new Neuron(0.00);
      neurons.push_back(this->n);
   }
}

Layer::~Layer() 
{
   delete n;
}
