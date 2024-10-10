#include <iostream>
#include <cstdlib>
#include "../header/Ackley.h"

using namespace std;

double randomSearch(OptimizationProblem *problem, int dimension, int maxEvaluations);

int main(int argc, char *argv[])
{
    srand(time(0));

    for (int i = 0; i < 1; ++i) {

        randomSearch(new Ackley(), 2, 1);

    }
    
    return 0;
}

double randomSearch(OptimizationProblem *problem, int dimension, int maxEvaluations)
{
    double currentResult, bestResult;

    for (int i = 0; i < maxEvaluations; ++i) {

        currentResult = problem->findSolution(dimension);
        cout << "Result is: " << currentResult << endl;
    }
}