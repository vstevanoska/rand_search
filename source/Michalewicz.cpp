#define _USE_MATH_DEFINES

#include "../header/Michalewicz.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Michalewicz::Michalewicz() 
{
    lowerCon = 0.0f;
    upperCon = M_PI;
}

double Michalewicz::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))


    cout << "Michalewicz vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;

    //declare used constants in equation
    short m = 10;

    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i)
        sum += sin(generatedValues[i]) * pow(sin((double)(((i + 1) * pow(generatedValues[i], 2)) / M_PI)), (2 * m));

    return (-1) * sum;
}