#ifndef TRID_H
#define TRID_H

#include "OptimizationProblem.h"

using namespace std;

class Trid : public OptimizationProblem
{
    public:

    Trid(int dimension);       //make a copy constructor instead of this
    ~Trid(){};

    double findSolution(short dimension);
};

#endif