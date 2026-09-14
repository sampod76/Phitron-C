

#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
    int node, toNode, cost;
    Edge(int node, int toNode, int cost)
    {
        this->node = node;
        this->toNode = toNode;
        this->cost = cost;
    }
};
int totalNode, totalEdge;
vector<Edge> edge_list;
long long int distanceArr[1005];
void bellman_ford()
{
    // totalNode - 1 বার loop চালাতে হবে (Bellman-Ford rule)
    for (int i = 1; i <= totalNode - 1; i++)
    {
        for (auto edge : edge_list)
        {
            int fromNode = edge.node;
            int toNode = edge.toNode;
            long long int cost = edge.cost;
            long long int currentDistForm = distanceArr[fromNode];
            long long int currentDistTo = distanceArr[toNode];
            if (currentDistForm != LLONG_MAX)
            {
                if (currentDistForm + cost < currentDistTo)
                {
                    distanceArr[toNode] = currentDistForm + cost;
                }
            }
        }
    }
    //
    bool isCycle = false;
    for (auto edge : edge_list)
    {
        int fromNode = edge.node;
        int toNode = edge.toNode;
        long long int cost = edge.cost;
        long long int currentDistForm = distanceArr[fromNode];
        long long int currentDistTo = distanceArr[toNode];
        if (currentDistForm != LLONG_MAX)
        {
            if (currentDistForm + cost < currentDistTo)
            {
                isCycle = true;
            }
        }
    }
    if (isCycle)
    {
        cout << "Negative Cycle Detected";
        return;
    }
    int query;
    cin >> query;
    while (query--)
    {
        int dist;
        cin >> dist;
        if (distanceArr[dist] == LLONG_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << distanceArr[dist] << endl;
        }
    }
};
int main()
{
    cin >> totalNode >> totalEdge;
    // edge_list.resize(totalEdge + 5);
    while (totalEdge--)
    {
        long long int node, toNode, cost;
        cin >> node >> toNode >> cost;

        edge_list.push_back(Edge(node, toNode, cost));
    }
    for (int i = 1; i <= totalNode; i++)
    {
        distanceArr[i] = LLONG_MAX;
    }
    int src;
    cin >> src;
    distanceArr[src] = 0;
    bellman_ford();

    return 0;
}
