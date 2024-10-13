#define _USE_MATH_DEFINES

#include "../header/Michalewicz.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Michalewicz::Michalewicz() 
{
    lowerCon = 0.0;
    upperCon = M_PI;
}

double Michalewicz::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //declare used constants in equation
    short m = 10;


    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i)
        sum += sin(generatedValues[i]) * pow(sin((double)(((i + 1) * pow(generatedValues[i], 2)) / M_PI)), (2 * m));

    return (-1.0) * sum;
}