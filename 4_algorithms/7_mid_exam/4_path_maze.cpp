#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> directions = {
    {0, 1},  // right
    {0, -1}, // left
    {-1, 0}, // up
    {1, 0},  // down
};
char grid[1005][1005];
bool visited[1005][1005];
int level[1005][1005];
// please see 1 hour 06 min => https://drive.google.com/file/d/1IC85O8dULLfuxjmBXZQ-E7zsTN0bnJ9L/view   // why use pair<int, int>
pair<int, int> parent[1005][1005];
int totalRow, totalCol;
bool isValid(int nextRow, int nextCol)
{
    if (nextRow < 0 || nextRow >= totalRow || nextCol < 0 || nextCol >= totalCol)
    {
        return false;
    }
    return true;
};
void bfs(int srcRow, int srcCol)
{
    queue<pair<int, int>> cellQueue;
    cellQueue.push({srcRow, srcCol});
    visited[srcRow][srcCol] = true;
    level[srcRow][srcCol] = 0;
    // parent[srcRow][srcCol] = {-1,-1};
    while (!cellQueue.empty())
    {
        // bar kora anta hoba
        pair<int, int> parentCell = cellQueue.front();
        cellQueue.pop();
        int parentRow = parentCell.first;
        int parentCol = parentCell.second;
        // kag kortahoba
        // child barkor queue push
        for (int i = 0; i < 4; i++)
        {
            int nextRow = parentRow + directions[i].first;
            int nextCol = parentCol + directions[i].second;
            if (isValid(nextRow, nextCol) && visited[nextRow][nextCol] == false && grid[nextRow][nextCol] != '#')
            {
                cellQueue.push({nextRow, nextCol});
                visited[nextRow][nextCol] = true;
                level[nextRow][nextCol] = level[parentRow][parentCol] + 1;
                parent[nextRow][nextCol] = {parentRow, parentCol};
            }
        }
    }
}
int main()
{
    cin >> totalRow >> totalCol;
    int dRow = 0, dCol = 0, rRow = 0, rCol = 0;
    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            cin >> grid[row][col];
            if (grid[row][col] == 'D')
            {
                dRow = row;
                dCol = col;
            }
            if (grid[row][col] == 'R')
            {
                rRow = row;
                rCol = col;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    memset(level, 0, sizeof(level));
    bfs(rRow, rCol);
    // cout << level[dRow][dCol];

    if (visited[dRow][dCol])
    {

        int distRow = dRow;
        int distCol = dCol;
        while (true)
        {
            pair<int, int> parentsCell = parent[distRow][distCol];
            distRow = parentsCell.first;
            distCol = parentsCell.second;
            // cout << grid[distRow][distCol];
            if (grid[distRow][distCol] == 'R')
            {
                break;
            }
            grid[distRow][distCol] = 'X';
        }

        for (int row = 0; row < totalRow; row++)
        {
            for (int col = 0; col < totalCol; col++)
            {
                cout << grid[row][col];
            }
            cout << endl;
        }
    }
    else
    {
        for (int row = 0; row < totalRow; row++)
        {
            for (int col = 0; col < totalCol; col++)
            {
                cout << grid[row][col];
            }
            cout << endl;
        }
    }

    return 0;
}