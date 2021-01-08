#pragma once

#include <random>
#include <iostream>
#include <fstream>

extern std::string DEBUG_STRING;
extern bool DEBUG;
extern int ITERATION;
extern std::string TEST_STRING;

// Declarations
int parse_config(std::string cfgFile);

namespace rand_generator {
    double rand_gen_norm_dist();
}