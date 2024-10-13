#include <iostream>
#include <cstdlib>
#include <math.h>

#include "../header/includes.h"

using namespace std;

double randomSearch(OptimizationProblem *problem, int dimension, int maxEvaluations);

void calculateStatistics(short problem, vector<double> *data);

int main(int argc, char *argv[])
{
    srand(time(0));     //seeding for rand number generator

    short problemNr = 12;     //number of problems that random search is solving    

    vector<vector<double>> results;

    //prepare vector of vectors for best solutions to problems
    for (int i = 0; i < problemNr; ++i) {

        vector<double> temp;
        results.push_back(temp);
    }
    
    cout << "Calculating";

    //solve problems
    for (int i = 0; i < 100; ++i) {

        results[0].push_back(randomSearch(new Sphere(),         2, 10000));
        results[1].push_back(randomSearch(new Ackley(),         2, 10000));
        results[2].push_back(randomSearch(new Griewank(),       2, 10000));
        results[3].push_back(randomSearch(new Rastrigin(),      2, 10000));
        results[4].push_back(randomSearch(new Schwefel(),       2, 10000));
        results[5].push_back(randomSearch(new Rosenbrock(),     2, 10000));
        results[6].push_back(randomSearch(new Trid(2),          2, 10000));
        results[7].push_back(randomSearch(new Bukin(),          2, 10000));
        results[8].push_back(randomSearch(new CarromTable(),    2, 10000));
        results[9].push_back(randomSearch(new StyblinskiTang(), 2, 10000));
        results[10].push_back(randomSearch(new Levy(),          2, 10000));
        results[11].push_back(randomSearch(new Michalewicz(),   2, 10000));

        cout << ".";
    }

    cout << endl << endl;
    
    for (int i = 0; i < problemNr; ++i)
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

    //calculate average and find minimum
    
    for (int i = 0; i < data->size(); ++i) {
        avg += data->at(i);

        if (data->at(i) < min)
            min = data->at(i);
    }

    avg = (double)(avg / data->size());

    //calculate standard deviation

    for (int i = 0; i < data->size(); ++i)
        std += pow((data->at(i) - avg), 2);

    std = sqrt((double)(std / data->size()));

    //choose correct problem name for output string

    string algorithmName;

    switch (problem) {

        case 0:
            algorithmName = "Sphere";
            break;
        case 1:
            algorithmName = "Ackley";
            break;
        case 2:
            algorithmName = "Griewank";
            break;
        case 3:
            algorithmName = "Rastrigin";
            break;
        case 4:
            algorithmName = "Schwefel";
            break;
        case 5:
            algorithmName = "Rosenbrock";
            break;
        case 6:
            algorithmName = "Trid";
            break;
        case 7:
            algorithmName = "Bukin";
            break;
        case 8:
            algorithmName = "CarromTable";
            break;
        case 9:
            algorithmName = "StyblinskiTang";
            break;
        case 10:
            algorithmName = "Levy";
            break;
        case 11:
            algorithmName = "Michalewicz";
            break;
    }

    cout << algorithmName << " min: " << min << " avg: " << avg << " std: " << std << endl;
    return; 
}