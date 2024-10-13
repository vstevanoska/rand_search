#ifndef ACKLEY_H
#define ACKLEY_H

#include "OptimizationProblem.h"

class Ackley : public OptimizationProblem
{
    public:

    Ackley();
    ~Ackley(){};

    double findSolution(int dimension);
};

#endif