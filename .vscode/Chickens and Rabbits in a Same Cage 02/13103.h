#include <iostream>

using namespace std;

class CageObserver
{
protected:
    CageObserver() : head(0), feet(0) {}

    int head;
    int feet;
};

class AnimalCounter : virtual public CageObserver
{
protected:
    AnimalCounter(int f) : count(0), feet(f) {}

    void Count()
    {
        count += 1;
        CageObserver::head += 1;
        CageObserver::feet += feet;
    }

    void Undo()
    {
        count -= 1;
        CageObserver::head -= 1;
        CageObserver::feet -= feet;
    }

    int count;
    int feet;
};

class RabbitCounter : public AnimalCounter
{
protected:
    RabbitCounter() : AnimalCounter(4) {}
};

class ChickenCounter : public AnimalCounter
{
protected:
    ChickenCounter() : AnimalCounter(2) {}
};

class ChickenNRabbitProblem : public ChickenCounter, RabbitCounter
{
public:
    ChickenNRabbitProblem(int h, int f) : targetHead(h), targetFeet(f) {}

    void Solve();

private:
    int targetHead;
    int targetFeet;

    bool CheckSolution()
    {
        if ((CageObserver::head == targetHead) && (CageObserver::feet == targetFeet))
            return true;
        else
            return false;
    }

    void PrintSolution()
    {
        cout << "Chicken: " << ChickenCounter::count << ", Rabbit: " << RabbitCounter::count << endl;
    }
};

/* function.cpp */
/*
#include "function.h"

void ChickenNRabbitProblem::Solve(){
    
}
*/