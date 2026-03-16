#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> direction = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1}   // right
};
char grid[105][105];
bool visited[105][105];
int level[105][105];
int totalRow, totalCol;
bool isValid(int nextRow, int nextCol)
{
    if (nextRow < 0 || nextRow >= totalRow || nextCol < 0 || nextCol >= totalCol)
    {
        return false;
    }
    return true;
}
//? https://phitron.io/ph068/video/ph068-3_10-variations-of-2d-grid
void bfs(int startRow, int startCol)
{
    queue<pair<int, int>> cellQueue;
    cellQueue.push({startRow, startCol});
    visited[startRow][startCol] = true;
    level[startRow][startCol] = 0;
    while (!cellQueue.empty())
    {
        // bar kora anta hoba
        pair<int, int> parentsCell = cellQueue.front();
        cellQueue.pop();
        int parRow = parentsCell.first;
        int parCol = parentsCell.second;
        for (int i = 0; i < 4; i++)
        {
            int nextRow = parRow + direction[i].first;
            int nextCol = parCol + direction[i].second;
            if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol] && grid[nextRow][nextCol] == '.')
            {
                cellQueue.push({nextRow, nextCol});
                visited[nextRow][nextCol] = true;
                level[nextRow][nextCol] = level[parRow][parCol] + 1;
            }
        }
    }
};
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
    memset(level, -1, sizeof(level));
    //
    int startRow, startCol;
    cin >> startRow >> startCol;
    //
    int distRow, distCol;
    cin >> distRow >> distCol;
    //
    bfs(startRow, startCol);
    cout << level[distRow][distCol];
    return 0;
}

/*
// '#' মানে block বা obstacle
// এই cell টি pass করা যাবে না, তাই BFS/DFS এখানে visit করবে না
input:

3 4
....
.#..
.#..
1 2
2 0




output:
3

*/