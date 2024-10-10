#ifndef SCHWEFEL_H
#define SCHWEFEL_H

#include "OptimizationProblem.h"

using namespace std;

class Schwefel : public OptimizationProblem
{
    public:

    Schwefel();
    ~Schwefel(){};

    double findSolution(short dimension);
};

#endif