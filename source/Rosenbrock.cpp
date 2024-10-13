#define _USE_MATH_DEFINES

#include "../header/Rosenbrock.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Rosenbrock::Rosenbrock() 
{
    lowerCon = -5.0;
    upperCon = 10.0;
}

double Rosenbrock::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size() - 1; ++i)
        sum += 100 * pow((generatedValues[i + 1] - pow(generatedValues[i], 2)), 2) + pow((generatedValues[i] - 1), 2);


    return sum;
}