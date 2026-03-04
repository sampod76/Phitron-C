#include <bits/stdc++.h>

using namespace std;
vector<int> adj_list[1005];
bool visitedArr[1005];
int level[1005];
void bfs(int src)
{
    queue<int> nodeQueue;
    nodeQueue.push(src);
    visitedArr[src] = true;
    level[src] = 0;
    while (!nodeQueue.empty())
    {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();
        //
        for (int child : adj_list[currentNode])
        {
            if (!visitedArr[child])
            {
                nodeQueue.push(child);
                visitedArr[child] = true;
                level[child] = level[currentNode] + 1;
            }
        }
    }
};
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    //
    while (totalEdge--)
    {
        int src, dist;
        cin >> src >> dist;
        adj_list[src].push_back(dist);
        adj_list[dist].push_back(src);
    }
    memset(visitedArr, false, sizeof(visitedArr));
    memset(level, -1, sizeof(level));
    int src, dist;
    cin >> src >> dist;
    bfs(src);
    for (int i = 0; i < totalNode; i++)
    {
        cout << i << " --> " << level[i] << endl;
    }

    cout << level[dist];
    return 0;
}

/* input:

7 8
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
0
4

node = 7
edge = 8
source = 0
destination = 4
*/

/* my question
7 9
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
0 6
0
6
*/