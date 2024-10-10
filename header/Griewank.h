#ifndef GRIEWANK_H
#define GRIEWANK_H

#include "OptimizationProblem.h"

using namespace std;

class Griewank : public OptimizationProblem
{
    public:

    Griewank();
    ~Griewank(){};

    double findSolution(short dimension);
};

#endif