#define _USE_MATH_DEFINES

#include "../header/Griewank.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Griewank::Griewank() 
{
    lowerCon = -600.0f;
    upperCon = 600.0f;
}

double Griewank::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double sum = 0, prod = 1;

    for (int i = 0; i < generatedValues.size(); ++i) {
        sum += (double)(pow(generatedValues[i], 2) / 4000);
        prod *= cos((double)(generatedValues[i] / (double)sqrt(i + 1)));
    }

    return sum - prod + 1;
}