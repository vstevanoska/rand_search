#define _USE_MATH_DEFINES

#include "../header/Bukin.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Bukin::Bukin() 
{
    lowerCon = -15.0; //of first coordinate
    upperCon = -5.0;  //of first coordinate

    lowerConSecond = -3.0;
    upperConSecond = 3.0;
}

double Bukin::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    //generate value of first coordinate
    generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))

    //generate value of second coordinate
    generatedValues.push_back(lowerConSecond + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperConSecond - lowerConSecond)))));


    //calculate

    double term1 = 100 * sqrt(abs(generatedValues[1] - (0.01 * pow(generatedValues[0], 2))));
    double term2 = 0.01 * abs(generatedValues[0] + 10);

    return term1 + term2;
}