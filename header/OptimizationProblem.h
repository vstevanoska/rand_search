#ifndef OPTIMIZATIONPROBLEM_H
#define OPTIMIZATIONPROBLEM_H

using namespace std;

#include <iostream>

class OptimizationProblem 
{
    public:

    virtual ~OptimizationProblem(){};

    virtual double findSolution(short dimension) {};
    
    protected:

    float lowerCon;
    float upperCon;
};

#endif