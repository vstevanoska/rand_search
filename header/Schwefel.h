#ifndef SCHWEFEL_H
#define SCHWEFEL_H

#include "OptimizationProblem.h"

class Schwefel : public OptimizationProblem
{
    public:

    Schwefel();
    ~Schwefel(){};

    double findSolution(int dimension);
};

#endif