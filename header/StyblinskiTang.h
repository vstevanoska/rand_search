#ifndef STYBLINSKITANG_H
#define STYBLINSKITANG_H

#include "OptimizationProblem.h"

class StyblinskiTang : public OptimizationProblem
{
    public:

    StyblinskiTang();
    ~StyblinskiTang(){};

    double findSolution(int dimension);
};

#endif