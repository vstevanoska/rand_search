#define _USE_MATH_DEFINES

#include "../header/CarromTable.h"
#include <vector>
#include <cstdlib>
#include <math.h>

CarromTable::CarromTable() 
{
    lowerCon = -10.0;
    upperCon = 10.0;
}

double CarromTable::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double term1 = (-1.0 / 30.0) * exp(2 * abs(1 - (double)(sqrt(pow(generatedValues[0], 2) + pow(generatedValues[1], 2)) / M_PI)));
    
    double term2 = pow(cos(generatedValues[0]), 2) * pow(cos(generatedValues[1]), 2);

    return term1 * term2;
}