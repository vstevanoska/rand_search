#define _USE_MATH_DEFINES

#include "../header/Ackley.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Ackley::Ackley() 
{
    lowerCon = -32.768;
    upperCon = 32.768;
}

double Ackley::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //declare used constants in equation
    short a = 20;
    double b = 0.2, c = 2 * M_PI;


    //calculate

    double sum1 = 0.0, sum2 = 0.0;

    for (int i = 0; i < generatedValues.size(); ++i) {
        sum1 += pow(generatedValues[i], 2);
        sum2 += cos(c * generatedValues[i]);
    }

    double term1 = ((-1) * a) * exp((-1) * b * sqrt(sum1 / generatedValues.size()));
    double term2 = (-1) * exp(sum2 / generatedValues.size());

    return term1 + term2 + a + exp(1.0);
}