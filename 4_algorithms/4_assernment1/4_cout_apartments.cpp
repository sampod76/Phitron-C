#include <bits/stdc++.h>
// https://www.hackerrank.com/contests/a1-algorithm-b8/challenges/count-apartments
using namespace std;
vector<pair<int, int>> directions = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1}   // right
};
char grid[1001][1001];
bool visited[1001][1001];
int totalRow, totalCol;
bool isValid(int nextRow, int nextCol)
{
    if (nextRow < 0 || nextCol < 0 || nextRow >= totalRow || nextCol >= totalCol)
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
        if (isValid(nextRow, nextCol) && visited[nextRow][nextCol] == false && grid[nextRow][nextCol] == '.')
        {
            dfs(nextRow, nextCol);
        }
    }
}
int main()
{
    cin >> totalRow >> totalCol;
    //

    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            char inp;
            cin >> inp;
            grid[row][col] = inp;
        }
    }
    int count = 0;
    for (int row = 0; row < totalRow; row++)
    {
        for (int col = 0; col < totalCol; col++)
        {
            if (!visited[row][col] && grid[row][col] == '.')
            {
                dfs(row, col);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}

/*
একটি ম্যাপ গ্রিডে . রুম এবং # দেয়াল।
চারদিকে সংযুক্ত রুমগুলো মিলিয়ে কতটি আলাদা অ্যাপার্টমেন্ট আছে তা বের করতে হবে
input:
5 8
########
#..#...#
####.#.#
#..#...#
########

output: 3

*/