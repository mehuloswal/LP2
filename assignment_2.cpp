#include <bits/stdc++.h>
using namespace std;

map<vector<vector<int>>, bool> visited;
vector<vector<int>> goal(3, vector<int>(3));

bool visit(vector<vector<int>> a)
{
    if (visited[a] == true)
        return true;
    else
        return false;
}
int manhattan(vector<vector<int>> a, int moves)
{
    int dist = moves;
    for (int i = 0; i < 3; i++) // for initial-state
    {
        for (int j = 0; j < 3; j++)
        {
            // if (a[i][j] != 0)
            // {
            //     for (int k = 0; k < 3; k++) // for goal-state
            //     {
            //         for (int l = 0; l < 3; l++)
            //         {
            //             if (a[i][j] == goal[k][l])
            //                 dist += abs(i - k) + abs(j - l); // calculating the manhattan distance.
            //         }
            //     }
            // }
            if (a[i][j] != goal[i][j])
            {
                dist++; // calculating the hamilton distance.
            }
        }
    }
    return dist;
    // f(x) -> manhattan distance(number of misplaced tiles by comparing the current state and the goal state)
}
bool isGoal(vector<vector<int>> a)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != goal[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool check(int i, int j)
{
    if (i >= 0 && i <= 2 && j >= 0 && j <= 2)
        return true;
    else
        return false;
}
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

vector<vector<vector<int>>> neighbours(vector<vector<int>> a)
{
    pair<int, int> pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
            {
                pos.first = i;  // 0
                pos.second = j; // 0
                break;
            }
        }
    }
    vector<vector<vector<int>>> ans;
    for (int k = 0; k < 4; k++)
    {
        int cx = pos.first;
        int cy = pos.second;
        vector<vector<int>> n = a;
        if (check(cx + dx[k], cy + dy[k]))
        {
            swap(n[cx + dx[k]][cy + dy[k]], n[cx][cy]);
            ans.push_back(n);
        }
    }
    return ans;
}

void printMatrix(vector<vector<int>> s)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // printf("%d ", s[i][j]);
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    cout << "|" << endl;
    cout << "v" << endl;
    cout << "\n";
}
void solve(vector<vector<int>> a, int moves)
{
    printMatrix(a);
    if (isGoal(a))
    {
        cout << "Done\n"
             << "------------------\n";
        return;
    }
    vector<vector<int>> test;
    vector<vector<vector<int>>> ns = neighbours(a);
    vector<vector<vector<int>>>::iterator it;
    visited[a] = true;
    int cost = 10000;
    for (it = ns.begin(); it != ns.end(); it++)
    {
        vector<vector<int>> temp = *it;
        if (!visit(temp))
        {
            if (manhattan(temp, moves + 1) < cost)
            {
                cost = manhattan(temp, moves + 1);
                test = temp;
            }
        }
    }
    solve(test, moves + 1);
}
int main()
{
    vector<vector<int>> a(3, vector<int>(3));
    cout << "Enter the initial state of 8-puzzle game:[ Example Below ] "
         << "\n\t\t\t\t 1 2 3 \n\t\t\t\t 4 0 5 \n\t\t\t\t 6 7 8" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "=========================================================" << endl;
    cout << "Enter the goal state of 8-puzzle game:[ Example Below ]"
         << "\n\t\t\t\t 1 2 3 \n\t\t\t\t 4 0 5 \n\t\t\t\t 6 7 8" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> goal[i][j];
        }
    }

    cout << "\n\n\nSolution...\n\n";

    solve(a, 0);
}