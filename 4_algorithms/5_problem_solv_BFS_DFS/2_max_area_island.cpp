#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool visited[105][105];
    int cnt = 0;
    int mx = 0;

    vector<pair<int, int>> directions = {
        {-1, 0}, // up
        {1, 0},  // down
        {0, -1}, // left
        {0, 1}   // right
    };

    int totalRow, totalCol;

    bool isValid(int nextRow, int nextCol)
    {
        if (nextRow < 0 || nextCol < 0 || nextRow >= totalRow ||
            nextCol >= totalCol)
            return false;

        return true;
    }

    void dfs(int srcRow, int srcCol, vector<vector<int>> &grid)
    {
        visited[srcRow][srcCol] = true;
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = srcRow + directions[i].first;
            int nextCol = srcCol + directions[i].second;

            if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol] &&
                grid[nextRow][nextCol] == 1)
            {
                dfs(nextRow, nextCol, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        totalRow = grid.size();
        totalCol = grid[0].size();

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    cnt = 0;
                    dfs(i, j, grid);
                    mx = max(cnt, mx);
                }
            }
        }

        return mx;
    }
};

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> grid(row, vector<int>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.maxAreaOfIsland(grid) << endl;

    return 0;
}

/* input:
4 5
0 0 1 0 0
1 1 1 0 0
0 1 0 0 1
0 0 0 1 1
*/