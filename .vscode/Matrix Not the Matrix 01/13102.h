#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix(int r, int c) : row(r), col(c) {}

    void readInput()
    {
        val.clear();
        for (int k = 0; k < row * col; k++)
        {
            int v;
            cin >> v;
            val.push_back(v);
        }
    }

    Matrix operator+(const Matrix &other);
    Matrix operator-(const Matrix &other);
    Matrix operator*(const Matrix &other);
    friend ostream &operator<<(ostream &os, const Matrix &mat);

private:
    int row, col;
    vector<int> val;
};

/* function.cpp */
/*
#include "function.h"

ostream &operator<<(ostream &os, const Matrix &mat){

}
*/