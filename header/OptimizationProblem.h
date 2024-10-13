#ifndef OPTIMIZATIONPROBLEM_H
#define OPTIMIZATIONPROBLEM_H

class OptimizationProblem 
{
    public:

    virtual ~OptimizationProblem(){};

    virtual double findSolution(int dimension) {};
    
    protected:

    double lowerCon;    //lower constraint of the search space
    double upperCon;    //upper constraint of the search space
};

#endif