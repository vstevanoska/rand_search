#ifndef ROSENBROCK_H
#define ROSENBROCK_H

#include "OptimizationProblem.h"

using namespace std;

class Rosenbrock : public OptimizationProblem
{
    public:

    Rosenbrock();
    ~Rosenbrock(){};

    double findSolution(short dimension);
};

#endif