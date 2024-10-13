#ifndef MICHALEWICZ_H
#define MICHALEWICZ_H

#include "OptimizationProblem.h"

class Michalewicz : public OptimizationProblem
{
    public:

    Michalewicz();
    ~Michalewicz(){};

    double findSolution(int dimension);
};

#endif