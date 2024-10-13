#ifndef ROSENBROCK_H
#define ROSENBROCK_H

#include "OptimizationProblem.h"

class Rosenbrock : public OptimizationProblem
{
    public:

    Rosenbrock();
    ~Rosenbrock(){};

    double findSolution(int dimension);
};

#endif