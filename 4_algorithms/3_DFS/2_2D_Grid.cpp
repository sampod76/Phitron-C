// 2D Grid=>  https://prnt.sc/nq-ing7GZzLy
// https://phitron.io/ph068/video/ph068-3_6-dfs-on-2d-grid-implementation-i
// best animation:  https://phitron.io/ph068/video/ph068-3_8-dfs-on-2d-grid-animated
#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool visited[105][105];
vector<pair<int, int>> directions = {
    // 4 direction movement (Up, Down, Left, Right)
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1}   // right
}; // Serial order mandatory না। শুধু চারটা direction combination থাকলেই হবে।
// Duplicate direction থাকা যাবে না।
int row, col;
bool isValid(int newRow, int newCol)
{
    if (newRow < 0 || newRow >= row || newCol < 0 || newCol >= col)
    {
        return false;
    }
    return true;
}
void dfs(int srcRow, int srcCol)
{
    cout << srcRow << " " << srcCol << endl;
    visited[srcRow][srcCol] = true;
    for (int i = 0; i < 4; i++)
    {
        int newRow = srcRow + directions[i].first;
        int newCol = srcCol + directions[i].second;
        // প্রতিটি node থেকে 4টা direction (up, down, left, right) check করা হয়
        // তাই theoretically Nটি * 4 বার loop run হতে পারে
        // Example: যদি 12টা node visit হয় তাহলে loop execute ≈ 12 * 4 = 48 times
        // কিন্তু print বা dfs call হবে শুধু valid এবং unvisited node এর জন্য
        // cout << newRow << " " << newCol << endl;
        if (isValid(newRow, newCol) && visited[newRow][newCol] == false)
        {
            dfs(newRow, newCol);
        }
    }
};
int main()
{

    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            /*
                int g1;
                cin >> g1;
                grid[i][j] = g1;
            */
            // shortcut
            cin >> grid[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int srcRow, srcCol;
    cin >> srcRow >> srcCol;
    dfs(srcRow, srcCol);
    return 0;
}

/*
input:

3 4
....
....
....
1 2


output:
1 2 => src/main pointer
0 2
2 2
1 1
1 3

*/