#define _USE_MATH_DEFINES

#include "../header/Rastrigin.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Rastrigin::Rastrigin() 
{
    lowerCon = -5.12;
    upperCon = 5.12;
}

double Rastrigin::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))



    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i) 
        sum += (pow(generatedValues[i], 2) - (10.0 * cos(2 * M_PI * generatedValues[i])));

    return (10.0 * generatedValues.size()) + sum;
}