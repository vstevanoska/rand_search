using namespace std;

class OptimizationProblem 
{
    public:

    virtual double findSolution(short dimension) {
        return 1;
    }
    
    protected:

    float lowerCon;
    float upperCon;
};