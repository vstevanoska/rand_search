#define _USE_MATH_DEFINES

#include "../header/Bukin.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Bukin::Bukin() 
{
    lowerCon = -15.0f; //of first coordinate
    upperCon = -5.0f;  //of first coordinate

    lowerConSecond = -3.0f;
    upperConSecond = 3.0f;
}

double Bukin::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    //generate value of first coordinate
    generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))

    //generate value of second coordinate
    generatedValues.push_back(lowerConSecond + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperConSecond - lowerConSecond))))); //lower + (rand / (RANDMAX / (upper - lower)))


    //calculate

    double term1 = 100 * sqrt(abs(generatedValues[1] - (0.01 * pow(generatedValues[0], 2))));
    double term2 = 0.01 * abs(generatedValues[0] + 10);

    return term1 + term2;
}