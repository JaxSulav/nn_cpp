#include "../include/Utils.h"

std::string DEBUG_STRING = "false";
bool DEBUG = false;
int ITERATION = 0;
std::string TEST_STRING = "";


// Parse the configurations from cfg file
int parse_config(std::string cfgFile)
{
    std::ifstream input;
    input.open(cfgFile);

    if (!input.is_open()){
        return 1;
    }

    int idx = 0;
    while(input){
        std::string line;
        std::getline(input, line, ':');

        input >> std::ws; // For Whitespaces

        if (idx == 0){
            input >> DEBUG_STRING;
            if (DEBUG_STRING == "true"){
                DEBUG = true;
            }
        }else if (idx == 1){
            input >> ITERATION;
        }else if (idx == 2){
            input >> TEST_STRING;
        }
        else{
            break;
        }

        idx++;
    }

    return 0;
}


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