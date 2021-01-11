#include "function.h"

int main()
{
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "new")
        {
            int r, c;
            cin >> r >> c;
            Matrix mat = Matrix(r, c);
            mat.readInput();
            cout << mat;
        }
        else if (cmd == "add")
        {
            int r, c;
            cin >> r >> c;
            Matrix mat1 = Matrix(r, c);
            mat1.readInput();

            cin >> r >> c;
            Matrix mat2 = Matrix(r, c);
            mat2.readInput();

            cout << mat1 + mat2;
        }
        else if (cmd == "sub")
        {
            int r, c;
            cin >> r >> c;
            Matrix mat1 = Matrix(r, c);
            mat1.readInput();

            cin >> r >> c;
            Matrix mat2 = Matrix(r, c);
            mat2.readInput();

            cout << mat1 - mat2;
        }
        else if (cmd == "mul")
        {
            int r, c;
            cin >> r >> c;
            Matrix mat1 = Matrix(r, c);
            mat1.readInput();

            cin >> r >> c;
            Matrix mat2 = Matrix(r, c);
            mat2.readInput();

            cout << mat1 * mat2;
        }
    }
    return 0;
}