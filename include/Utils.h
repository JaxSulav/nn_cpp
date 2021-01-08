#pragma once

#include <random>
#include <iostream>
#include <fstream>
#include <string>  

extern std::string DEBUG_STRING;
extern bool DEBUG;
extern int ITERATION;
extern int LEARNING_RATE;

// Declarations
int parse_config(std::string cfgFile);

namespace rand_generator {
    double rand_gen_norm_dist();
}