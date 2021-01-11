#include "13103.h"

void ChickenNRabbitProblem::Solve()
{
    for (int i = 0; i < targetHead + 1; i++)
    {
        // count chicken
        for (int k = 0; k < i; k++)
        {
            ChickenCounter::Count();
        }

        for (int j = 0; j < targetHead + 1; j++)
        {
            // count rabbit
            for (int k = 0; k < j; k++)
            {
                RabbitCounter::Count();
            }

            // Check
            if (CheckSolution())
            {
                PrintSolution();
                return;
            }

            // undo rabbit
            for (int k = 0; k < j; k++)
            {
                RabbitCounter::Undo();
            }
        }

        // undo chicken
        for (int k = 0; k < i; k++)
        {
            ChickenCounter::Undo();
        }
    }
    cout << "no solutions" << endl;
}

int main()
{
    int head, feet;
    cin >> head >> feet;
    ChickenNRabbitProblem prob = ChickenNRabbitProblem(head, feet);
    prob.Solve();
    return 0;
}