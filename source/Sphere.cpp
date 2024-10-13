#define _USE_MATH_DEFINES

#include "../header/Sphere.h"
#include <vector>
#include <cstdlib>
#include <math.h>

Sphere::Sphere() 
{
    lowerCon = -100.0; //of odd coordinate
    upperCon = 100.0;  //of odd coordinate

    lowerConEven = -10.0;
    upperConEven = 10.0;
}

double Sphere::findSolution(int dimension)
{
    //generate vector of random float values within the constrained space

    vector<double> generatedValues;

    for (int i = 0; i < dimension; ++i) {
        if (i % 2 == 0) //1, 3, 5... odd values
            generatedValues.push_back(lowerCon + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))
        else            //2, 4, 6... even values
            generatedValues.push_back(lowerConEven + (static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (upperConEven - lowerConEven)))));

    }


    //calculate

    double sum = 0;
    
    for (int i = 0; i < generatedValues.size(); ++i)
        sum += pow(generatedValues[i], 2);

    return sum;
}