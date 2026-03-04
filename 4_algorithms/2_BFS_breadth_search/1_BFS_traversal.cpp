#include <bits/stdc++.h>
using namespace std;
//
// adjacency list: প্রতিটি node এর সাথে কোন কোন node connected তা রাখবে
vector<int> adjacencyList[1005]; // max node limit (1005) -->check question

// visited array: কোন node already visit হয়েছে কিনা track করার জন্য
bool visited[1005];

// BFS function
//$ https://phitron.io/ph068/video/ph068-2_4-bfs-traversal
void bfs(int startNode)
{
    queue<int> nodeQueue;
    // starting node queue তে push
    nodeQueue.push(startNode);
    // start node কে visited mark করা
    visited[startNode] = true;

    while (!nodeQueue.empty())
    {
        // queue থেকে current node বের করা
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        // node print (visit action)
        cout << currentNode << " ";

        // current node এর সব neighbour check
        for (int neighbourNode : adjacencyList[currentNode])
        {
            if (visited[neighbourNode] == false)
            {
                // unvisited neighbour queue তে push
                nodeQueue.push(neighbourNode);
                // visited mark
                visited[neighbourNode] = true;
            }
        }
    }
}

int main()
{
    int totalNodes, totalEdges;
    cin >> totalNodes >> totalEdges;

    /*
    Source : যে node থেকে connection শুরু হয়।
    Destination: যে node-এ connection যায়।
    */

    while (totalEdges--)
    {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;

        // undirected graph
        adjacencyList[sourceNode].push_back(destinationNode);
        adjacencyList[destinationNode].push_back(sourceNode);
    }

    // visited array initialize (false)
    memset(visited, false, sizeof(visited));
    // BFS traversal start from node 0
    bfs(0);

    return 0;
}

/*
input:

7 7
0 1
1 3
1 4
3 2
4 6
3 5
4 5
*/