#define _USE_MATH_DEFINES

#include "../header/StyblinskiTang.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

StyblinskiTang::StyblinskiTang() 
{
    lowerCon = -5.0f;
    upperCon = 5.0f;
}

double StyblinskiTang::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i)
        generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))

    cout << "Styb vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;


    //calculate

    double sum = 0;

    for (int i = 0; i < generatedValues.size(); ++i) 
        sum += (pow(generatedValues[0], 4) - 16 * pow(generatedValues[i], 2) + 5 * generatedValues[i]);

    return (double)(sum / 2);
}