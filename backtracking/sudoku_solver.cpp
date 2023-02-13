// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printSudoku(vector<vector<int>> &sudoku, int n)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < n; j++)
            cout << sudoku[i][j] << " ";
        cout << endl;
    }
}

/*
Alternative way to achive notIn--
bool canPut(vector<vector<int>> &sudoku, int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == num || sudoku[row][i] == num)
        {
            return false;
        }
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
        {
            return false;
        }
    }

    return true;
}
*/

bool notInRow(vector<vector<int>> &sudoku, int x, int i)
{
    for (int k = 0; k < 9; k++)
    {
        if (sudoku[x][k] == i)
            return false;
    }
    return true;
}

bool notInCol(vector<vector<int>> &sudoku, int y, int i)
{
    for (int k = 0; k < 9; k++)
    {
        if (sudoku[k][y] == i)
            return false;
    }
    return true;
}

bool notInBlock(vector<vector<int>> &sudoku, int x, int y, int k)
{
    if (x < 3 && y < 3) // 1
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    else if (x < 3 && 3 <= y && y < 6) // 2
    {
        for (int i = 0; i < 3; i++)
            for (int j = 3; j < 6; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
	else if (x < 3 && 6 <= y && y < 9) // 3
    {
        for (int i = 0; i < 3; i++)
            for (int j = 6; j < 9; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    else if (3 <= x && x < 6 && y < 3) // 4
    {
        for (int i = 3; i < 6; i++)
            for (int j = 0; j < 3; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    else if (3 <= x && x < 6 && 3 <= y && y < 6)  // 5
    {
        for (int i = 3; i < 6; i++)
            for (int j = 3; j < 6; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    else if (3 <= x && x < 6 && y < 9)  // 6
    {
        for (int i = 3; i < 6; i++)
            for (int j = 6; j < 9; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    else if (6 <= x && x < 9 && y < 3)  // 7
    {
        for (int i = 6; i < 9; i++)
            for (int j = 0; j < 3; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    else if (6 <= x && x < 9 && 3 <= y && y < 6)  // 8
    {
        for (int i = 6; i < 9; i++)
            for (int j = 3; j < 6; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    else if (6 <= x && x < 9 && 6 <= y && y < 9)  // 9
    {
        for (int i = 6; i < 9; i++)
            for (int j = 6; j < 9; j++)
                if (sudoku[i][j] == k)
                    return false;
    }
    return true;
}

bool tryFill(vector<vector<int>> &sudoku, int n, int x, int y)
{
    if (x == n - 1 && y == n) return true;
    if (y > n - 1)
    {
        y = 0;
        x++;
    }
    if (sudoku[x][y] != 0)
        return tryFill(sudoku, n, x, y + 1);
        
    for (int i = 1; i <= 9; i++)
    {
        if (notInRow(sudoku, x, i) && notInCol(sudoku, y, i) && notInBlock(sudoku, x, y, i))
        {
            sudoku[x][y] = i;
            if (tryFill(sudoku, n, x, y + 1))
                return true;
            sudoku[x][y] = 0;
        }
    }
    return false;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    int n = sudoku.size();
	tryFill(sudoku, n, 0, 0);
}


int main()
{
    // ONT WAY TO MAKE 2D VECTOR OF FIXED SIZE
    // vector<vector<int>> sudoku(9);
    // for (int i = 0; i < 9; i++)
    //     sudoku[i] = vector<int>(9);
    // for (int i = 0; i < 9; i++)
    //     for (int j = 0; j < 9; j++)
    //         sudoku[i][j] = 0;
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int tmp; cin >> tmp;
            sudoku[i][j] = tmp;
        }
    }
    solveSudoku(sudoku);
    cout << endl;
    printSudoku(sudoku, sudoku.size());
}