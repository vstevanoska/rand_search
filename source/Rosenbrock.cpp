#define _USE_MATH_DEFINES

#include "../header/Rosenbrock.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Rosenbrock::Rosenbrock() 
{
    lowerCon = -5.0f;
    upperCon = 10.0f;
}

double Rosenbrock::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size() - 1; ++i)
        sum += 100 * pow((generatedValues[i + 1] - pow(generatedValues[i], 2)), 2) + pow((generatedValues[i] - 1), 2);


    return sum;
}