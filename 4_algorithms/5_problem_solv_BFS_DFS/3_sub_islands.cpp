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

bool isValid(int nextRow, int nextCol)
{
    if (nextRow < 0 || nextCol < 0 || nextRow >= totalRow || nextCol >= totalCol)
        return false;

    return true;
}
int coutSubIslands(
    vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    totalRow = grid1.size();
    totalCol = grid2[0].size();
    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            if (!visited[row][col] && isValid(row, col))
            {
            }
        }
    }
};
int main()
{
    int a, b;

    cout << " " << endl;
    return 0;
}