#ifndef UTILITY_H
#define UTILITY_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <cstdlib>
#include <random>
#include <atomic>

// C++ std usings
using std::make_shared;
using std::shared_ptr;

//Defined constants (infinity + our definition of pi)

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi /180.0;
}

inline double random_double() {
    static std::atomic<int> seed_counter{0};
    thread_local std::mt19937 generator(seed_counter.fetch_add(1));
    thread_local std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // returns a random real in [min, max)
    return min + (max-min) * random_double();
}

//Common Headers
#include "vec3.h"
#include "interval.h"
#include "ray.h"
#include "color.h"


#endif