#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph068/video/ph068-13_3-roads-not-only-in-berland-implementation
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
    if (leader1 == leader2)
    {
        return;
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
    // memset(parentArr, -1, sizeof(parentArr));
    for (int i = 0; i < totalNode; i++)
    {
        parentArr[i] = -1;
        group_size[i] = 1;
    };
    vector<pair<int, int>> removeEdge;
    vector<pair<int, int>> createRoadEdge;
    for (int i = 0; i < totalNode - 1; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        int leaderA = findLeader(nodeA);
        int leaderB = findLeader(nodeB);
        if (leaderA == leaderB)
        {
            removeEdge.push_back({nodeA, nodeB});
        }
        else
        {
            dsu_union(nodeA, nodeB);
        }
    }

    for (int i = 2; i <= totalNode; i++)
    {
        int leader1 = findLeader(1); // 1 node
        int leader2 = findLeader(i);
        if (leader1 != leader2)
        {
            createRoadEdge.push_back({1, i});
            dsu_union(1, i);
        }
    }
    cout << removeEdge.size() << endl;
    for (int i = 0; i < removeEdge.size(); i++)
    {
        cout << removeEdge[i].first << " " << removeEdge[i].second << " " << createRoadEdge[i].first << " " << createRoadEdge[i].second << endl;
    }

    return 0;
}