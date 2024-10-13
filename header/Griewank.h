#ifndef GRIEWANK_H
#define GRIEWANK_H

#include "OptimizationProblem.h"

class Griewank : public OptimizationProblem
{
    public:

    Griewank();
    ~Griewank(){};

    double findSolution(int dimension);
};

#endif