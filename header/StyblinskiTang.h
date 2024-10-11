#ifndef STYBLINSKITANG_H
#define STYBLINSKITANG_H

#include "OptimizationProblem.h"

using namespace std;

class StyblinskiTang : public OptimizationProblem
{
    public:

    StyblinskiTang();
    ~StyblinskiTang(){};

    double findSolution(short dimension);
};

#endif