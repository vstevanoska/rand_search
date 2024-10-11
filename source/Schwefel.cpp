#define _USE_MATH_DEFINES

#include "../header/Schwefel.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Schwefel::Schwefel() 
{
    lowerCon = -500.0f;
    upperCon = 500.0f;
}

double Schwefel::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    cout << "Schwefel vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;

    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i) 
        sum += generatedValues[i] * sin(sqrt(abs(generatedValues[i])));

    return (-1) * sum;
}