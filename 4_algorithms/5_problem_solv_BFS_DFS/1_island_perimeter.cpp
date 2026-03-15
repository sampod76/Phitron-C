#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int perimeterCount = 0;
    bool visited[105][105];

    vector<pair<int, int>> directions = {
        {-1, 0}, // up
        {1, 0},  // down
        {0, -1}, // left
        {0, 1}   // right
    };

    int totalRow, totalCol;

    bool isValid(int nextRow, int nextCol)
    {
        if (nextRow < 0 || nextCol < 0 || nextRow >= totalRow || nextCol >= totalCol)
            return false;

        return true;
    }

    void dfs(int srcRow, int srcCol, vector<vector<int>> &grid)
    {
        visited[srcRow][srcCol] = true;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = srcRow + directions[i].first;
            int nextCol = srcCol + directions[i].second;

            // Check all 4 directions of current land cell
            if (isValid(nextRow, nextCol) == false)
            {
                // Case 1: Neighbor cell grid এর বাইরে → অর্থাৎ island এর boundary
                // তাই এই side perimeter এর অংশ
                perimeterCount++;
            }
            else if (grid[nextRow][nextCol] == 0)
            {
                // Case 2: Neighbor cell water (0)
                // Land এর পাশে water থাকলে সেই edge perimeter
                perimeterCount++;
            }
            else if (!visited[nextRow][nextCol] && grid[nextRow][nextCol] == 1)
            {
                // Case 3: Neighbor cell land (1) এবং এখনো visit করা হয়নি
                // তাই DFS করে island এর বাকি অংশ explore করবো
                dfs(nextRow, nextCol, grid);
            }
        }
    }
    // https://phitron.io/ph068/video/ph068-5_2-island-perimeter-part-ii
    int islandPerimeter(vector<vector<int>> &grid)
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
                    dfs(i, j, grid);
                    return perimeterCount;
                }
            }
        }
        cout << perimeterCount;
        return 0;
    }
};

int main()
{
    int totalRow, totalCol;
    cin >> totalRow >> totalCol;

    vector<vector<int>> grid(totalRow, vector<int>(totalCol));

    for (int i = 0; i < totalRow; i++)
    {
        for (int j = 0; j < totalCol; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;

    int result = sol.islandPerimeter(grid);

    cout << result << endl;

    return 0;
}

/* //question:  https://prnt.sc/1akia6n6zUtR
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]

4 4
0 1 0 0
1 1 1 0
0 1 0 0
1 1 0 0

output: 16
*/