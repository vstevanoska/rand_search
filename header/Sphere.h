#ifndef SPHERE_H
#define SPHERE_H

#include "OptimizationProblem.h"

using namespace std;

class Sphere : public OptimizationProblem
{
    public:

    Sphere();
    ~Sphere(){};

    double findSolution(int dimension);

    private:

    //even- and odd-indexed variables have different constraints. Odd-indexed variable constraints are saved in parent class.

    double lowerConEven;    //even-indexed lower constraint
    double upperConEven;    //even-indexed upper constraint
};

#endif