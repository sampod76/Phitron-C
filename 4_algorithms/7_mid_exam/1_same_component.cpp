#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> directions = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1}   // right
};
bool visited[1005][1005];
char grid[1005][1005];
int totalRow, totalCol;

bool isValid(int nextRow, int nextCol)
{
    if (nextRow < 0 || nextRow >= totalRow || nextCol < 0 || nextCol >= totalCol)
    {
        return false;
    }
    return true;
};
void dfs(int srcRow, int srcCol)
{
    visited[srcRow][srcCol] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextRow = srcRow + directions[i].first;
        int nextCol = srcCol + directions[i].second;
        if (isValid(nextRow, nextCol) && visited[nextRow][nextCol] == false && grid[nextRow][nextCol] != '-')
        {

            dfs(nextRow, nextCol);
        }
    }
}
int main()
{
    cin >> totalRow >> totalCol;

    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {

            cin >> grid[row][col];
        }
    }

    memset(visited, false, sizeof(visited));

    int srcRow, srcCol;
    cin >> srcRow >> srcCol;
    int distRow, distCol;
    cin >> distRow >> distCol;
    dfs(srcRow, srcCol);
    if (visited[distRow][distCol])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}