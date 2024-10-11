#include <iostream>
#include <cstdlib>
#include <math.h>

#include "../header/includes.h"

using namespace std;

double randomSearch(OptimizationProblem *problem, int dimension, int maxEvaluations);

void calculateStatistics(short problem, vector<double> *data);

int main(int argc, char *argv[])
{
    srand(time(0));

    short algorithmNumber = 1;

    vector<vector<double>> results;

    //prepare datatype
    for (int i = 0; i < algorithmNumber; ++i) {

        vector<double> temp;
        results.push_back(temp);
    }
    
    //solve problems
    for (int i = 0; i < 5; ++i) {

        // results[0].push_back(randomSearch(new Sphere(),         2, 1));
        // results[1].push_back(randomSearch(new Ackley(),         2, 1));
        results[0].push_back(randomSearch(new Griewank(),       2, 1));
        // results[3].push_back(randomSearch(new Rastrigin(),      2, 1));
        // results[4].push_back(randomSearch(new Schwefel(),       2, 1));
        // results[5].push_back(randomSearch(new Rosenbrock(),     2, 1));
        // results[6].push_back(randomSearch(new Trid(2),          2, 1));
        // results[7].push_back(randomSearch(new Bukin(),          2, 1));
        // results[8].push_back(randomSearch(new CarromTable(),    2, 1));
        // results[9].push_back(randomSearch(new StyblinskiTang(), 2, 1));
        // results[10].push_back(randomSearch(new Levy(),          2, 1));
        // results[11].push_back(randomSearch(new Michalewicz(),   2, 1));
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
    cout << "All results: \n";

    for (int i = 0; i < data->size(); ++i)
        cout << data->at(i) << endl;

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

        case 0:
            algorithmName = "Sphere";
            break;
        case 1: //Griewank
            algorithmName = "Ackley";
            break;
        case 2: //Ackley
            algorithmName = "Griewank";
            break;
        case 3: //Griewank
            algorithmName = "Rastrigin";
            break;
        case 4: //Ackley
            algorithmName = "Schwefel";
            break;
        case 5: //Griewank
            algorithmName = "Rosenbrock";
            break;
        case 6: //Ackley
            algorithmName = "Trid";
            break;
        case 7: //Griewank
            algorithmName = "Bukin";
            break;
        case 8: //Ackley
            algorithmName = "CarromTable";
            break;
        case 9: //Griewank
            algorithmName = "StyblinskiTang";
            break;
        case 10: //Ackley
            algorithmName = "Levy";
            break;
        case 11: //Griewank
            algorithmName = "Michalewicz";
            break;
    }

    cout << algorithmName << " min: " << min << " avg: " << avg << " std: " << std << endl;
    return; 
}