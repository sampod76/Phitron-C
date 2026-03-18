#include <bits/stdc++.h>

using namespace std;
vector<int> adj_list[105];
int parent[105];
bool visited[105];
bool isCycle = false;
// https://phitron.io/ph068/video/ph068-6_2-detect-cycle-in-undirected-graph-using-bfs
void bfs(int startNode)
{
    queue<int> nodeQueue;
    nodeQueue.push(startNode);
    visited[startNode] = true;
    while (!nodeQueue.empty())
    {
        // bar kora anta hoba
        int current = nodeQueue.front();
        nodeQueue.pop();
        //
        for (int child : adj_list[current])
        {
            // https://prnt.sc/NZ_CC3-O5XBU
            // Undirected graph এ প্রতিটি node তার parent node এর সাথে সবসময় adjacent থাকে। তাই traversal করার সময় যদি আমরা আবার parent node-কে পাই, তাহলে সেটাকে cycle হিসেবে ধরা যাবে না—এটা একটি স্বাভাবিক back edge। কিন্তু যদি কোনো child node আগে থেকেই visited থাকে এবং সেই node যদি current node-এর parent না হয়, তাহলে বুঝতে হবে আমরা অন্য একটি পথ দিয়ে আবার সেই node-এ ফিরে এসেছি। এই পরিস্থিতি graph-এ একটি loop বা cycle থাকার প্রমাণ।
            if (visited[child] && parent[current] != child)
            {
                isCycle = true;
            }
            if (!visited[child])
            {
                visited[child] = true;
                parent[child] = current;
                nodeQueue.push(child);
            }
        }
    }
};
// or
void dfs(int srcNode)
{
    visited[srcNode] = true;
    for (int child : adj_list[srcNode])
    {
        if (visited[child] && parent[srcNode] != child)
        {
            isCycle = true;
        }
        if (!visited[child])
        {
            parent[child] = srcNode; // must best this is add dfs function up
            dfs(child);
        }
    }
};
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
    memset(parent, -1, sizeof(parent));
    isCycle = false;
    for (int nodeIdx = 0; nodeIdx < totalNodes; nodeIdx++)
    {
        if (!visited[nodeIdx])
        {
            bfs(nodeIdx);
            // dfs(nodeIdx)
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

/* https://phitron.io/ph068/video/ph068-6_2-detect-cycle-in-undirected-graph-using-bfs

*/