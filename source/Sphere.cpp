#define _USE_MATH_DEFINES

#include "../header/Sphere.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h> 
#include <iostream>

Sphere::Sphere() 
{
    lowerCon = -100.0f; //of odd coordinate
    upperCon = 100.0f;  //of odd coordinate

    lowerConEven = -10.0f;
    upperConEven = 10.0f;
}

double Sphere::findSolution(short dimension)
{
    //generate vector of random float values within the constrained space

    vector<float> generatedValues;

    for (int i = 0; i < dimension; ++i) {
        if (i % 2 == 0) //1, 3, 5... odd values
            generatedValues.push_back(lowerCon + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperCon - lowerCon))))); //lower + (rand / (RANDMAX / (upper - lower)))
        else            //2, 4, 6... even values
            generatedValues.push_back(lowerConEven + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperConEven - lowerConEven))))); //lower + (rand / (RANDMAX / (upper - lower)))

    }

    cout << "Sphere vector: ";
    for (int i = 0; i < generatedValues.size(); ++i)
        cout << generatedValues[i] << " ";
    cout << endl;

    //calculate

    double sum = 0;
    
    for (int i = 0; i < generatedValues.size(); ++i) {
        sum += pow(generatedValues[i], 2);
    }

    return sum;
}