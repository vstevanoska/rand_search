#define _USE_MATH_DEFINES

#include "../header/Schwefel.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Schwefel::Schwefel() 
{
    lowerCon = -500.0;
    upperCon = 500.0;
}

double Schwefel::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))

    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i) 
        sum += generatedValues[i] * sin(sqrt(abs(generatedValues[i])));

    return (-1.0) * sum;
}