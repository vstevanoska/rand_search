#ifndef RASTRIGIN_H
#define RASTRIGIN_H

#include "OptimizationProblem.h"

using namespace std;

class Rastrigin : public OptimizationProblem
{
    public:

    Rastrigin();
    ~Rastrigin(){};

    double findSolution(short dimension);
};

#endif