#include <bits/stdc++.h>
using namespace std;

// Direction moves (Right, Left, Up, Down)
vector<pair<int, int>> directions = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};

// Grid and helpers
char grid[1005][1005];
bool visited[1005][1005];
int distanceLevel[1005][1005];
// please see 1 hour 06 min => https://drive.google.com/file/d/1IC85O8dULLfuxjmBXZQ-E7zsTN0bnJ9L/view // why use pair<int, int>
pair<int, int> parentCell[1005][1005];

int totalRows, totalCols;

// Check valid cell inside grid
bool isValidCell(int row, int col)
{
    return (row >= 0 && row < totalRows && col >= 0 && col < totalCols);
}

// BFS traversal from source
void bfs(int startRow, int startCol)
{
    queue<pair<int, int>> queueCells;

    queueCells.push({startRow, startCol});
    visited[startRow][startCol] = true;
    distanceLevel[startRow][startCol] = 0;
    // parentCell[startRow][startCol] = {-1, -1};
    while (!queueCells.empty())
    {
        pair<int, int> currentCell = queueCells.front();
        queueCells.pop();

        int currentRow = currentCell.first;
        int currentCol = currentCell.second;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = currentRow + directions[i].first;
            int nextCol = currentCol + directions[i].second;

            if (isValidCell(nextRow, nextCol) &&
                !visited[nextRow][nextCol] &&
                grid[nextRow][nextCol] != '#')
            {
                queueCells.push({nextRow, nextCol});
                visited[nextRow][nextCol] = true;
                distanceLevel[nextRow][nextCol] = distanceLevel[currentRow][currentCol] + 1;
                parentCell[nextRow][nextCol] = {currentRow, currentCol};
            }
        }
    }
}

int main()
{
    cin >> totalRows >> totalCols;

    int destinationRow = 0, destinationCol = 0;
    int startRow = 0, startCol = 0;

    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalCols; col++)
        {
            cin >> grid[row][col];

            if (grid[row][col] == 'D')
            {
                destinationRow = row;
                destinationCol = col;
            }

            if (grid[row][col] == 'R')
            {
                startRow = row;
                startCol = col;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    memset(parentCell, -1, sizeof(parentCell));
    memset(distanceLevel, 0, sizeof(distanceLevel));

    bfs(startRow, startCol);

    if (visited[destinationRow][destinationCol])
    {
        int tempRow = destinationRow;
        int tempCol = destinationCol;

        while (tempRow != -1 && tempCol != -1)
        {
            pair<int, int> parent = parentCell[tempRow][tempCol];
            tempRow = parent.first;
            tempCol = parent.second;

            if (grid[tempRow][tempCol] == 'R')
            {
                break;
            }

            grid[tempRow][tempCol] = 'X';
        }
    }

    // Print final grid
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalCols; col++)
        {
            cout << grid[row][col];
        }
        cout << endl;
    }

    return 0;
}

/* input:
5 6
...D.#
.##..#
....#.
.R#...
.#.##.


output:
...D.#
.##X.#
.XXX#.
.R#...
.#.##.

*/