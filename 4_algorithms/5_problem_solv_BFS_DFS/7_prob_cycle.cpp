#include <bits/stdc++.h>

using namespace std;
vector<int> adj_list[100005];
bool visited[100005];
int parents[100005];
bool isCycle = false;
void dfs(int srcNode)
{
    visited[srcNode] = true;
    // parents[srcNode]=-1
    for (int child : adj_list[srcNode])
    {
        if (visited[child] && parents[srcNode] != child)
        {
            isCycle = true;
            // return ;
        }
        if (!visited[child])
        {
            parents[child] = srcNode;
            dfs(child);
        }
    }
}

int main()
{
    int totalNodes, totalEdges;
    cin >> totalNodes >> totalEdges;
    //
    while (totalEdges--)
    {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;

        // undirected graph
        adj_list[sourceNode].push_back(destinationNode);
        adj_list[destinationNode].push_back(sourceNode);
    }

    memset(visited, false, sizeof(visited));
    memset(parents, -1, sizeof(parents));
    for (int nodeIdx = 0; nodeIdx < totalNodes; nodeIdx++)
    {
        if (!visited[nodeIdx])
        {
            dfs(nodeIdx);
        }
    }
    if (isCycle)
    {
        cout << "is a cycle.";
    }
    else
    {
        cout << "No cycle in the graph.";
    }

    return 0;
}