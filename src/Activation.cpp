#include "../include/Activation.h"


namespace Activate
{
    double ACTIVATION_SIGMOID(double val) 
    {
        // f(x) = x / (1 + |x|)
        return (val / (1 + abs(val)));
    }
}