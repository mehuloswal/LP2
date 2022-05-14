#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{ // Returns 3D Matrix consisting of 2D answers
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}

int main()
{

    int queens;
    cout << "Enter the number of queens to be placed: ";
    cin >> queens;
    vector<vector<string>> answers = solveNQueens(queens);
    for (int i = 0; i < answers.size(); i++)
    {
        for (int j = 0; j < answers[i].size(); j++)
        {
            for (int k = 0; k < answers[i][j].length(); k++)
            {
                cout << answers[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}