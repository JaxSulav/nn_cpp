#include "../include/Activation.h"


namespace Activate
{
    double ACTIVATION_SIGMOID(double val) 
    {
        // f(x) = x / (1 + |x|)
        return (val / (1 + abs(val)));
    }
}
namespace Derive
{
    double DERIVATION_SIGMOID(double activatedVal) 
    {
        // f'(x) = f(x) * (1 - f(x)) 
        return(activatedVal * (1 - activatedVal));
    }
}