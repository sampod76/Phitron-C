#include <bits/stdc++.h>

using namespace std;
int parentArr[1005];
int group_size[1005];
// https://phitron.io/ph068/video/ph068-11_10-detect-cycle-in-undirected-graph-using-dsu-implementation
int findLeader(int node)
{

    if (parentArr[node] == -1)
        return node;
    int leader = findLeader(parentArr[node]);
    parentArr[node] = leader;

    return leader;
}
void dsu_union(int node1, int node2)
{
    int leader1 = findLeader(node1);
    int leader2 = findLeader(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        parentArr[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        parentArr[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{
    memset(parentArr, -1, sizeof(parentArr));
    memset(group_size, 1, sizeof(group_size));
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    //
    bool isCycle = false;
    while (totalEdge--)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        int leaderA = findLeader(nodeA);
        int leaderB = findLeader(nodeB);
        if (leaderA == leaderB)
        {
            isCycle = true;
        }
        else
        {
            dsu_union(nodeA, nodeB);
        }
    }
    if (isCycle)
    {
        cout << "Cycle Detected\n";
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}

/* // https://phitron.io/ph068/video/ph068-11_10-detect-cycle-in-undirected-graph-using-dsu-implementation
 input: https://prnt.sc/uHndp1xxjHUA
3 3
0 1
0 2
1 2

output: Cycle Detected
https://prnt.sc/VTGw3T1WPO5t
3 2
0 1
0 2

output: No cycle
*/