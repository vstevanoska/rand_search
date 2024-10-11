#define _USE_MATH_DEFINES

#include "../header/Ackley.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Ackley::Ackley() 
{
    lowerCon = -32.768f;
    upperCon = 32.768f;
}

double Ackley::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))

    cout << "Ackley vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;


    //declare used constants in equation
    short a = 20;
    float b = 0.2f;
    double c = 2 * M_PI;


    //calculate

    double sum1 = 0, sum2 = 0;

    for (int i = 0; i < generatedValues.size(); ++i) {
        sum1 += pow(generatedValues[i], 2);
        sum2 += cos(c * generatedValues[i]);
    }

    double term1 = ((-1) * a) * exp((-1) * b * sqrt(sum1 / generatedValues.size()));
    double term2 = (-1) * exp(sum2 / generatedValues.size());

    return term1 + term2 + a + exp(1);
}