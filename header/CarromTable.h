#ifndef CARROMTABLE_H
#define CARROMTABLE_H

#include "OptimizationProblem.h"

class CarromTable : public OptimizationProblem
{
    public:

    CarromTable();
    ~CarromTable(){};

    double findSolution(int dimension);
};

#endif