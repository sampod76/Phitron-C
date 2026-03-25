#include <bits/stdc++.h>

using namespace std;
int parentArr[100005];
int group_size[100005];
int totalComponent, maxSizeOfComp;
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
    if (leader1 == leader2)
    {
    }
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
};
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    //
    memset(parentArr, -1, sizeof(parentArr));
    for (int i = 0; i < totalNode; i++)
    {
        group_size[i] = 1;
    }
    totalComponent = totalNode;
    maxSizeOfComp = 1;
    return 0;
}