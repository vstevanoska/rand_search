#define _USE_MATH_DEFINES

#include "../header/Rastrigin.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Rastrigin::Rastrigin() 
{
    lowerCon = -5.12f;
    upperCon = 5.12f;
}

double Rastrigin::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))

    cout << "Rastrigin vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;


    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i) 
        sum += (pow(generatedValues[i], 2) - (10 * cos(2 * M_PI * generatedValues[i])));

    return (10 * generatedValues.size()) + sum;
}