#include <bits/stdc++.h>

using namespace std;
vector<int> adjacencyList[1005];
int visitedArr[1005];
void bfs(int src)
{
    queue<int> nodeQueue;
    nodeQueue.push(src);
    visitedArr[src] = true;
    while (!nodeQueue.empty())
    {
        // bar korta hoba
        int currentNode = nodeQueue.front();
        nodeQueue.pop();
        //
        for (int child : adjacencyList[currentNode])
        {
            if (visitedArr[child] == false)
            {
                nodeQueue.push(child);
                visitedArr[child] = true;
            }
        }
    }
};
// https://phitron.io/ph068/video/ph068-2_7-check-if-a-node-can-be-visited-or-not
int main()
{
    int totalNode, totalEdges;
    cin >> totalEdges >> totalEdges;
    //
    while (totalEdges--)
    {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;
        //
        adjacencyList[sourceNode].push_back(destinationNode);
        adjacencyList[destinationNode].push_back(sourceNode);
    }
    memset(visitedArr, false, sizeof(visitedArr));
    //
    int visitedNode, visitedDst;
    cin >> visitedNode >> visitedDst;
    //
    bfs(visitedNode);
    if (visitedArr[visitedDst])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

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
0
4
OUTPUT: YES
*/

/*
7 5
0 1
1 3
3 2
4 6
3 5
0
4
OUTPUT: NO
*/
