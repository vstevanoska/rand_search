#define _USE_MATH_DEFINES

#include "../header/StyblinskiTang.h"
#include <vector>
#include <cstdlib>
#include <math.h>

StyblinskiTang::StyblinskiTang() 
{
    lowerCon = -5.0;
    upperCon = 5.0;
}

double StyblinskiTang::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i)
        sum += (pow(generatedValues[0], 4) - (16.0 * pow(generatedValues[i], 2)) + (5.0 * generatedValues[i]));

    return (double)(sum / 2.0);
}