#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];

bool visited[105];
bool pathVisited[105]; // recursion stack track korar jonno
bool isCycle = false;
// https://phitron.io/ph068/video/ph068-6_6-detect-cycle-in-directed-graph-using-dfs
// best Animated:  https://phitron.io/ph068/video/ph068-6_7-detect-cycle-in-directed-graph-using-dfs-animated
void dfs(int srcNode)
{
    visited[srcNode] = true;
    pathVisited[srcNode] = true;

    for (int child : adj_list[srcNode])
    {
        if (visited[child] && pathVisited[child])
        {
            isCycle = true;
            // return;
        }

        if (!visited[child])
        {
            dfs(child);
        }
    }

    pathVisited[srcNode] = false;
}

int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;

    while (totalEdge--)
    {
        int sourceNode, distNode;
        cin >> sourceNode >> distNode;

        // Directed graph
        adj_list[sourceNode].push_back(distNode);
    }

    memset(visited, false, sizeof(visited));
    memset(pathVisited, false, sizeof(pathVisited));

    // sob component traverse kori
    for (int node = 0; node < totalNode; node++)
    {
        if (!visited[node])
        {
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