#define _USE_MATH_DEFINES

#include "../header/CarromTable.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

CarromTable::CarromTable() 
{
    lowerCon = -10.0f;
    upperCon = 10.0f;
}

double CarromTable::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))

    cout << "Carrom vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;


    //calculate

    double term1 = (-1 / 30) * exp(2 * abs(1 - ((double)(sqrt(pow(generatedValues[0], 2) + pow(generatedValues[1], 2)) / M_PI))));
    double term2 = pow(cos(generatedValues[0]), 2) * pow(cos(generatedValues[0]), 2);

    return term1 * term2;
}