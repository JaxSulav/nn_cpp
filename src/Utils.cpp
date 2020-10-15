#include "../include/Utils.h"


// Random number generator
namespace rand_generator
{
    // Random number from normal distribution
    double rand_gen_norm_dist() 
    {
        auto mean = 0;
        auto stdDev = 1;

        std::random_device randDev;
        std::mt19937_64 randGenerator(randDev());
        std::normal_distribution<> distribution(mean, stdDev);

        double randVal = distribution(randGenerator);

        // Values between 0 - 1
        while (randVal < 0 || randVal > 1){
            randVal = distribution(randGenerator);
        }

        return randVal;
    }
}