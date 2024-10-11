#ifndef CARROMTABLE_H
#define CARROMTABLE_H

#include "OptimizationProblem.h"

using namespace std;

class CarromTable : public OptimizationProblem
{
    public:

    CarromTable();
    ~CarromTable(){};

    double findSolution(short dimension);
};

#endif