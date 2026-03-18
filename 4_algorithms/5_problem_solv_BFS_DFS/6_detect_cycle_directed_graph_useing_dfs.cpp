#include <bits/stdc++.h>

using namespace std;
vector<int> adj_list[105];
int pathVisited[105]; // path as like road
bool visited[105];
bool isCycle = false;
void dfs(int srcNode)
{
    visited[srcNode] = true;
    pathVisited[srcNode] = true;
    for (int child : adj_list[srcNode])
    {
        if (visited[child] && pathVisited[child])
        {
            isCycle = true;
        }
        if (!visited[child])
        {
            dfs(child);
        }
    }
    pathVisited[srcNode] = false;
};
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    //
    while (totalEdge--)
    {
        int sourceNode, distNode;
        cin >> sourceNode >> distNode;
        adj_list[sourceNode].push_back(distNode);
    }
    memset(visited, false, sizeof(visited));
    memset(pathVisited, false, sizeof(pathVisited));

    for (int node = 0; node < totalNode; node++)
    {

        if (!visited[node])
        {
            // isCycle = false // when question ask check every connected/land is cycle
            dfs(node);
        }
    }

    if (isCycle)
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "Cycle Not Detected";
    }

    return 0;
}

/* input:

4 4
0 1
1 2
2 3
3 1

*/