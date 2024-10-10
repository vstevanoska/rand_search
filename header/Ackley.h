#include "OptimizationProblem.h"

using namespace std;

//try abstract class for all problems

class Ackley : public OptimizationProblem
{
    public:

    Ackley();
    ~Ackley();

    double findSolution(short dimension);
};