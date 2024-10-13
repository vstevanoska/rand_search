#ifndef RASTRIGIN_H
#define RASTRIGIN_H

#include "OptimizationProblem.h"

class Rastrigin : public OptimizationProblem
{
    public:

    Rastrigin();
    ~Rastrigin(){};

    double findSolution(int dimension);
};

#endif