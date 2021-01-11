#include "13103.h"
int main()
{
    int head, feet;
    cin >> head >> feet;
    ChickenNRabbitProblem prob = ChickenNRabbitProblem(head, feet);
    prob.Solve();
    return 0;
}