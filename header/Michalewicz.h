#ifndef MICHALEWICZ_H
#define MICHALEWICZ_H

#include "OptimizationProblem.h"

using namespace std;

class Michalewicz : public OptimizationProblem
{
    public:

    Michalewicz();
    ~Michalewicz(){};

    double findSolution(short dimension);
};

#endif