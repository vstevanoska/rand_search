#define _USE_MATH_DEFINES

#include "../header/Trid.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Trid::Trid(int dimension)
{
    lowerCon = (double)((-1.0) * pow(dimension, 2));
    upperCon = (double)(pow(dimension, 2));
}

double Trid::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double sum1 = 0, sum2 = 0;

    for (int i = 0; i < generatedValues.size(); ++i) {
        sum1 += pow(generatedValues[i] - 1, 2);

        if (i > 0)
            sum2 += (generatedValues[i] * generatedValues[i - 1]);
    }

    return sum1 - sum2;
}