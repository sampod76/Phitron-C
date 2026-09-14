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
bool isClosedIsland = true;
int totalClosedIsland = 0;

bool isValid(int nextRow, int nextCol)
{
    if (nextRow < 0 || nextCol < 0 || nextRow >= totalRow || nextCol >= totalCol)
        return false;

    return true;
}
// https://leetcode.com/problems/number-of-closed-islands/
// question:  https://prnt.sc/SDKNBZj_eSPx
// ph draw:  https://prnt.sc/FlD9tTSTkoKg
void dfs(int srcRow, int srcCol, vector<vector<int>> &grid)
{
    visited[srcRow][srcCol] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextRow = srcRow + directions[i].first;
        int nextCol = srcCol + directions[i].second;
        /*
       Closed Island এর মূল ধারণা:
       আমরা যদি island (0) এর উপর DFS করি, তাহলে চারদিকে check করবো। যদি island এর চারপাশে সব জায়গায় valid cell থাকে এবং সেগুলো water (1) দ্বারা ঘেরা থাকে তাহলে island টি closed।

       কিন্তু যদি DFS করার সময় এমন কোন neighbour পাই , যেটা grid এর বাইরে চলে যায় (মানে boundary স্পর্শ করে), তাহলে বুঝবো island টি সম্পূর্ণ ঘেরা না। তাই এটাকে closed island বলা যাবে না।
       */

        if (!isValid(nextRow, nextCol))
        {
            // grid এর বাইরে চলে গেছে → island boundary ছুঁয়েছে তাই এটি closed island না
            isClosedIsland = false;
        }
        if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol] && grid[nextRow][nextCol] == 0)
        {
            dfs(nextRow, nextCol, grid);
        }
    }
}

int closedIsland(vector<vector<int>> &grid)
{
    totalRow = grid.size();
    totalCol = grid[0].size();

    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            if (!visited[row][col] && grid[row][col] == 0)
            {
                isClosedIsland = true;

                dfs(row, col, grid);
                // cout << row << " " << col << " " << (isClosedIsland ? "true" : "false") << endl;
                if (isClosedIsland)
                {
                    totalClosedIsland++;
                }
            }
        }
    }

    return totalClosedIsland;
}

int main()
{

    cin >> totalRow >> totalCol;

    vector<vector<int>> grid(totalRow, vector<int>(totalCol));

    // input grid1
    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            cin >> grid[row][col];
        }
    }

    cout << closedIsland(grid) << endl;
}

/* question:  https://prnt.sc/SDKNBZj_eSPx
input:
5 8
1 1 1 1 1 1 1 0
1 0 0 0 0 1 1 0
1 0 1 0 1 1 1 0
1 0 0 0 0 1 0 1
1 1 1 1 1 1 1 0

// output: 2
*/