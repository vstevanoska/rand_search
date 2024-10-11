#define _USE_MATH_DEFINES

#include "../header/Trid.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Trid::Trid(int dimension)
{
    lowerCon = (float)((-1) * pow(dimension, 2));
    upperCon = (float)(pow(dimension, 2));
}

double Trid::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    cout << "Trid vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;

    //calculate

    double sum1 = 0, sum2 = 0;

    for (int i = 0; i < generatedValues.size(); ++i) {
        sum1 += pow(generatedValues[i] - 1, 2);

        if (i > 0)
            sum2 += (generatedValues[i] * generatedValues[i - 1]);
    }

    return sum1 - sum2;
}