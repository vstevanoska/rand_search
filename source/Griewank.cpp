#define _USE_MATH_DEFINES

#include "../header/Griewank.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Griewank::Griewank() 
{
    lowerCon = -600.0f;
    upperCon = 600.0f;
}

double Griewank::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double sum = 0.0, prod = 1.0;

    for (int i = 0; i < generatedValues.size(); ++i) {
        sum += (double)(pow(generatedValues[i], 2) / 4000.0);
        prod *= cos((double)(generatedValues[i] / (double)sqrt(i + 1)));
    }

    return sum - prod + 1;
}