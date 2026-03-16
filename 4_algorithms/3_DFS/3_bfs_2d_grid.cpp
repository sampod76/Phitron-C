#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> directions = {
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
void bfs(int startRow, int startCol)
{
    // cout << grid[startRow][startCol] << " ";
    queue<pair<int, int>> cellQueue;
    cellQueue.push({startRow, startCol});
    visited[startRow][startCol] = true;
    level[startRow][startCol] = 0;
    while (!cellQueue.empty())
    {
        // bar kora anta hoba
        pair<int, int> parentCell = cellQueue.front();
        cellQueue.pop();
        //
        int row = parentCell.first;
        int col = parentCell.second;
        // cout << row << " " << col;
        //
        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + directions[i].first;
            int nextCol = col + directions[i].second;
            if (isValid(nextRow, nextCol) == true && visited[nextRow][nextCol] == false)
            {
                //
                cellQueue.push({nextRow, nextCol});
                visited[nextRow][nextCol] = true;
                level[nextRow][nextCol] = level[row][col] + 1;
            }
        }
        // cout << endl;
    }
}
int main()
{
    cin >> totalRow >> totalCol;
    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            /*
                int g1;
                cin >> g1;
                grid[row][col] = g1;
            */

            // shortcut
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
input:

3 4
....
....
....
1 2
2 0



output:
3

*/