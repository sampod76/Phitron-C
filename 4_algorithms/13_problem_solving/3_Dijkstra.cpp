#include <bits/stdc++.h>

using namespace std;
#define ll long long int

vector<pair<ll, ll>> adj_list[100005];
ll distanceArr[100005];
ll parentArr[100005];
void dijkstra(ll srcNode)
{
    priority_queue<
        pair<ll, ll>,
        vector<pair<ll, ll>>,
        greater<pair<ll, ll>>>
        nodePQueue;
    nodePQueue.push({0, srcNode});
    distanceArr[srcNode] = 0;
    while (!nodePQueue.empty())
    {
        // bar kora anta hoba
        pair<ll, ll> parent = nodePQueue.top();
        nodePQueue.pop();
        ll parentNode = parent.second;    // src to parent node
        ll parentDistance = parent.first; // parent node dist
                                          //
        if (parentDistance > distanceArr[parentNode])
            continue;
        for (auto child : adj_list[parentNode])
        {
            ll child_node = child.first;    // child node
            ll child_weight = child.second; // child node weight/cost
            //
            ll child_node_dist = distanceArr[child_node]; // child node dist
            if (parentDistance + child_weight < child_node_dist)
            {
                distanceArr[child_node] = parentDistance + child_weight;
                nodePQueue.push({distanceArr[child_node], child_node}); // example: {1+3,5}
                parentArr[child_node] = parentNode;
            }
        }
    }
}
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    while (totalEdge--)
    {
        int srcNode, distNode, weight;
        cin >> srcNode >> distNode >> weight;

        // undirected graph
        adj_list[srcNode].push_back({distNode, weight});
        adj_list[distNode].push_back({srcNode, weight});
    }
    for (int node = 1; node <= totalNode; node++)
    {
        distanceArr[node] = LLONG_MAX;
        parentArr[node] = -1;
    }
    dijkstra(1);
    if (distanceArr[totalNode] == LLONG_MAX)
    { // totalNode/n
        cout << -1 << endl;
    }
    else
    {
        ll node = totalNode; // n
        vector<ll> path;
        while (node != -1)
        {
            path.push_back(node);
            node = parentArr[node];
        }
        reverse(path.begin(), path.end());
        for (auto node : path)
        {
            cout << node << " ";
        }
    }
    return 0;
}

/* input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

output:
 */