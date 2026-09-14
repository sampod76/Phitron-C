#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph068/video/ph068-11_3-find-operation-implementation
int leadParent[1005];
int find(int node)
{
    // int temp = node;
    while (leadParent[node] != -1)
    {
        node = leadParent[node];
    }
    return node;
}
int main()
{
    memset(leadParent, -1, sizeof(leadParent));
    leadParent[0] = 1;
    leadParent[1] = -1;
    leadParent[2] = 1;
    leadParent[3] = 1;
    leadParent[4] = 5;
    leadParent[5] = 3;

    cout << find(4) << " ";

    return 0;
}