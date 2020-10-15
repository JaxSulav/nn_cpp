#include "../include/Utils.h"


namespace rand_generator_norm_dist
{
    double rand_gen() 
    {
        auto mean = 0;
        auto stdDev = 1;

        std::random_device randDev;
        std::mt19937_64 randGenerator(randDev());
        std::normal_distribution<> distribution(mean, stdDev);

        double randVal = distribution(randGenerator);

        // Between 0 - 1
        while (randVal < 0 || randVal > 1){
            randVal = distribution(randGenerator);
        }

        return randVal;
    }
}