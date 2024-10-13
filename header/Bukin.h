#ifndef BUKIN_H
#define BUKIN_H

#include "OptimizationProblem.h"

class Bukin : public OptimizationProblem
{
    public:

    Bukin();
    ~Bukin(){};

    double findSolution(int dimension);

    private:

    //2d only problem. x1 and x2 have different constraints to search space. x1 constraints are saved in parent class.

    double lowerConSecond;   //x2 lower constraint
    double upperConSecond;   //x2 upper constraint
};

#endif