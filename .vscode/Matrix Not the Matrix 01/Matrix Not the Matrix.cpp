#include "13102.h"

Matrix Matrix::operator+(const Matrix &other)
{
    if (!(row == other.row && col == other.col))
    {
        cout << "Uncalculable" << endl;
        return Matrix(0, 0);
    }

    Matrix mat = Matrix(row, col);
    for (int i = 0; i < val.size(); i++)
    {
        mat.val.push_back(val[i] + other.val[i]);
    }
    return mat;
}

Matrix Matrix::operator-(const Matrix &other)
{
    if (!(row == other.row && col == other.col))
    {
        cout << "Uncalculable" << endl;
        return Matrix(0, 0);
    }

    Matrix mat = Matrix(row, col);
    for (int i = 0; i < val.size(); i++)
    {
        mat.val.push_back(val[i] - other.val[i]);
    }
    return mat;
}

Matrix Matrix::operator*(const Matrix &other)
{
    if (!(col == other.row))
    {
        cout << "Uncalculable" << endl;
        return Matrix(0, 0);
    }

    Matrix mat = Matrix(row, other.col);
    for (int i = 0; i < row * other.col; i++)
    {
        int v = 0;
        int r = i / other.col;
        int c = i % other.col;
        for (int k = 0; k < col; k++)
        {
            v += val[r * col + k] * other.val[k * other.col + c];
        }
        mat.val.push_back(v);
    }
    return mat;
}

ostream &operator<<(ostream &os, const Matrix &mat)
{
    for (int i = 0; i < mat.row; i++)
    {
        if (i == 0)
            os << "[ ";
        else
            os << "  ";

        for (int j = 0; j < mat.col; j++)
        {
            os << mat.val[i * mat.col + j];
            if (j == mat.col - 1)
            {
                if (i == mat.row - 1)
                    os << " ]" << endl;
                else
                    os << endl;
            }
            else
                os << " ";
        }
    }
    return os;
}
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
