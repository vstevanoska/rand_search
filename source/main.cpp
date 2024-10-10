#include <iostream>
#include <cstdlib>
#include "Ackley.cpp"
#include "Griewank.cpp"
#include <math.h>

using namespace std;

double randomSearch(OptimizationProblem *problem, int dimension, int maxEvaluations);

void calculateStatistics(short problem, vector<double> *data);

int main(int argc, char *argv[])
{
    srand(time(0));

    short algorithmNumber = 2;

    vector<vector<double>> results;

    //prepare datatype
    for (int i = 0; i < algorithmNumber; ++i) {

        vector<double> temp;
        results.push_back(temp);
    }
    
    //solve problems
    for (int i = 0; i < 100; ++i) {

        results[0].push_back(randomSearch(new Ackley()  , 2, 10000));
        results[1].push_back(randomSearch(new Griewank(), 2, 10000));

    }
    
    for (int i = 0; i < algorithmNumber; ++i)
        calculateStatistics(i, &results[i]);

    return 0;
}

double randomSearch(OptimizationProblem *problem, int dimension, int maxEvaluations)
{
    double currentResult, bestResult;

    //initialize starting value for bestResult
    bestResult = problem->findSolution(dimension);

    //find best result for problem
    for (int i = 0; i < maxEvaluations - 1; ++i) {

        currentResult = problem->findSolution(dimension);

        if (currentResult < bestResult)
            bestResult = currentResult;
    }

    return bestResult;
}

void calculateStatistics(short problem, vector<double> *data)
{
    double avg = 0, std = 0, min = data->at(0);

    for (int i = 0; i < data->size(); ++i) {
        avg += data->at(i);

        if (data->at(i) < min)
            min = data->at(i);
    }

    avg = (double)(avg / data->size());

    for (int i = 0; i < data->size(); ++i)
        std += pow((data->at(i) - avg), 2);

    std = sqrt((double)(std / data->size()));

    string algorithmName;

    switch (problem) {

        case 0: //Ackley
            algorithmName = "Ackley";
            break;
        case 1: //Griewank
            algorithmName = "Griewank";
            break;
    }

    cout << algorithmName << " min: " << min << " avg: " << avg << " std: " << std << endl;
    return; 
}