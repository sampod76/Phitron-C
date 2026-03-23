

#include <bits/stdc++.h>
using namespace std;
// https://phitron.io/ph068/video/ph068-11_3-find-operation-implementation

int parentArr[1005];
int group_size[1005];

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
    dsu_union(1, 2);
    dsu_union(0, 2);
    dsu_union(3, 2);

    for (int i = 0; i < 6; i++)
    {
        cout << i << " leader => " << parentArr[i] << endl;
    }

    return 0;
}
