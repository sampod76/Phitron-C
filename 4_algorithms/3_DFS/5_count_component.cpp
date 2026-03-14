/*

*/
#include <bits/stdc++.h>

using namespace std;
vector<int> adj_list[1005];
bool visitedArr[1005];
void dfs(int src)
{

    cout << src << " ";
    visitedArr[src] = true;
    for (int child : adj_list[src])
    {
        if (!visitedArr[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    while (totalEdge--)
    {
        int src, dist;
        cin >> src >> dist;
        adj_list[src].push_back(dist);
        adj_list[dist].push_back(src);
    }
    memset(visitedArr, false, sizeof(visitedArr));
    int numberCom = 0;
    for (int i = 0; i < totalNode; i++)
    {
        if (!visitedArr[i])
        {
            dfs(i); //
            numberCom++;
        }
    }

    return 0;
}

/* // https://phitron.io/ph068/video/ph068-3_11-number-of-components
input: please view=>  https://prnt.sc/vU7KfFtw42Xo
7 6
1 2
0 5
2 3
6 7
4 5
1 3

output: 0 1 3 2 5 6 4

*/
