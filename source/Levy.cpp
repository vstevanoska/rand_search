#define _USE_MATH_DEFINES

#include "../header/Levy.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Levy::Levy() 
{
    lowerCon = -10.0;
    upperCon = 10.0;
}

double Levy::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //generate transformed values

    vector<double> w;

    for (int i = 0; i < generatedValues.size(); ++i)
        w.push_back(1 + (double)((generatedValues[i] - 1) / 4.0));


    //calculate

    double term1 = pow(sin(M_PI * w[0]), 2);
    double term3 = pow(w[w.size() - 1] - 1, 2) * (1 + pow(sin(2.0 * M_PI * w[w.size() - 1]), 2));

    double sum = 0;

    for (int i = 0; i < w.size() - 1; ++i)
        sum += pow(w[i] - 1, 2) * (1 + 10 * pow(sin(M_PI * w[i] + 1), 2));

    return term1 + sum + term3;
}