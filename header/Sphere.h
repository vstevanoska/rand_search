#ifndef SPHERE_H
#define SPHERE_H

#include "OptimizationProblem.h"

using namespace std;

class Sphere : public OptimizationProblem
{
    public:

    Sphere();
    ~Sphere(){};

    double findSolution(short dimension);

    private:

    float lowerConEven;
    float upperConEven;
};

#endif