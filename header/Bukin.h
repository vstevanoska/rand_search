#ifndef BUKIN_H
#define BUKIN_H

#include "OptimizationProblem.h"

using namespace std;

class Bukin : public OptimizationProblem
{
    public:

    Bukin();
    ~Bukin(){};

    double findSolution(short dimension);

    private:

    float lowerConSecond;
    float upperConSecond;
};

#endif