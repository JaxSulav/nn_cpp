#include "../include/Utils.h"

std::string DEBUG_STRING = "false";
bool DEBUG = false;
int ITERATION = 0;
int LEARNING_RATE = 0;


// Parse the configurations from cfg file
int parse_config(std::string cfgFile)
{
    std::ifstream input;
    input.open(cfgFile);

    if (!input.is_open()){
        return 1;
    }

    std::cout << "------- Configs and Params::: --------" << std::endl;

    int idx = 0;
    while(input){
        std::string line;
        std::getline(input, line, ':');


        if (idx == 0){
            input >> DEBUG_STRING;
            if (DEBUG_STRING == "true"){
                DEBUG = true;
            }
            std::cout << "- " << line << ": " << DEBUG_STRING << std::endl;
        }else if (idx == 1){
            input >> ITERATION;
            std::cout << "- " << line << ": " << std::to_string(ITERATION) << std::endl;
        }else if (idx == 2){
            input >> LEARNING_RATE;
            std::cout << "- " << line << ": " << std::to_string(LEARNING_RATE) << std::endl;
        }
        else{
            break;
        }
        
        input >> std::ws; // For Whitespaces

        idx++;
    }

    std::cout << "------- ! --------\n" << std::endl;

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