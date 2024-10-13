#ifndef TRID_H
#define TRID_H

#include "OptimizationProblem.h"

class Trid : public OptimizationProblem
{
    public:

    Trid(int dimension);    //copy constructor, constraints depend on dimension of problem
    ~Trid(){};

    double findSolution(int dimension);
};

#endif