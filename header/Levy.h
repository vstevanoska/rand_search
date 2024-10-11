#ifndef LEVY_H
#define LEVY_H

#include "OptimizationProblem.h"

using namespace std;

class Levy : public OptimizationProblem
{
    public:

    Levy();
    ~Levy(){};

    double findSolution(short dimension);
};

#endif