#ifndef LEVY_H
#define LEVY_H

#include "OptimizationProblem.h"

class Levy : public OptimizationProblem
{
    public:

    Levy();
    ~Levy(){};

    double findSolution(int dimension);
};

#endif