#ifndef ACKLEY_H
#define ACKLEY_H

#include "OptimizationProblem.h"

using namespace std;

class Ackley : public OptimizationProblem
{
    public:

    Ackley();
    ~Ackley(){};

    double findSolution(short dimension);
};

#endif