#include <bits/stdc++.h>

using namespace std;
int parentArr[100005];
int group_size[100005];
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
    int numOfCycle = 0;
    ;
    while (totalEdge--)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        int leaderA = findLeader(nodeA);
        int leaderB = findLeader(nodeB);
        if (leaderA == leaderB)
        {
            numOfCycle++;
        }
        else
        {
            dsu_union(nodeA, nodeB);
        }
    }
    cout << numOfCycle;
    return 0;
}