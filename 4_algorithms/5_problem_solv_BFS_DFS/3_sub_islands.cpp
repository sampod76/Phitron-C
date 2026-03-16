#include <bits/stdc++.h>
using namespace std;

bool visited[505][505];

vector<pair<int, int>> directions = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1}   // right
};

int totalRow, totalCol;
bool isSubIsland = true;
int totalSubIsland = 0;

bool isValid(int nextRow, int nextCol)
{
    if (nextRow < 0 || nextCol < 0 || nextRow >= totalRow || nextCol >= totalCol)
        return false;

    return true;
}
// https://leetcode.com/problems/count-sub-islands/
// question:  https://prnt.sc/b_aMQhb0JkDg
// ph draw:  https://prnt.sc/xEv7QX3P1BSi
void dfs(int srcRow, int srcCol, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    visited[srcRow][srcCol] = true;

    // গুরুত্বপূর্ণ check : যদি grid2 তে land থাকে কিন্তু grid1 এ water থাকে | তাহলে এটা sub-island হতে পারবে না
    if (grid1[srcRow][srcCol] == 0)
    {
        isSubIsland = false;
    }

    for (int i = 0; i < 4; i++)
    {
        int nextRow = srcRow + directions[i].first;
        int nextCol = srcCol + directions[i].second;

        if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol] && grid2[nextRow][nextCol] == 1)
        {
            dfs(nextRow, nextCol, grid1, grid2);
        }
    }
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    totalRow = grid1.size();
    totalCol = grid1[0].size();

    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            if (!visited[row][col] && grid2[row][col] == 1)
            {
                isSubIsland = true;

                dfs(row, col, grid1, grid2);
                // cout << row << " " << col << " " << (isSubIsland ? "true" : "false") << endl;
                if (isSubIsland)
                {
                    totalSubIsland++;
                }
            }
        }
    }

    return totalSubIsland;
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> grid1(row, vector<int>(col));
    vector<vector<int>> grid2(row, vector<int>(col));

    // input grid1
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid1[i][j];
        }
    }

    // input grid2
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid2[i][j];
        }
    }

    cout << countSubIslands(grid1, grid2) << endl;
}

/* //question https://prnt.sc/b_aMQhb0JkDg
input:
5 5

1 1 1 0 0
0 1 1 1 1
0 0 0 0 0
1 0 0 0 0
1 1 0 1 1

1 1 1 0 0
0 0 1 1 1
0 1 0 0 0
1 0 1 1 0
0 1 0 1 0

// output: 3
*/