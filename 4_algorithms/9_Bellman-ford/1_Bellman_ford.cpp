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
int distanceArr[1005];
vector<Edge> edge_list;
// https://phitron.io/ph068/video/ph068-9_6-bellman-ford-animated
void bellman_ford() //
{
    // totalNode - 1 বার loop চালাতে হবে (Bellman-Ford rule)
    for (int i = 0; i < totalNode - 1; i++) // O(V) → এই loop V-1 ≈ V বার চলে
    {
        // সব edge এর উপর traverse করবো
        for (auto edge : edge_list) // O(E) → প্রতিবার সব edge একবার করে traverse
        {
            int fromNode = edge.node; // যেখান থেকে edge শুরু
            int toNode = edge.toNode; // যেখান পর্যন্ত যাচ্ছে
            int weight = edge.cost;   // edge এর weight (cost)

            int currentDistFrom = distanceArr[fromNode]; // source থেকে fromNode এর current lowest/shortest distance
            int currentDistTo = distanceArr[toNode];     // source থেকে toNode এর current lowest/shortest distance

            // যদি fromNode এখনও infinity (INT_MAX) থাকে, তাহলে বুঝতে হবে source থেকে এখনো এই node-এ পৌঁছানো যায়নি,
            // তাই এই node থেকে অন্য node-এ যাওয়াও সম্ভব না → skip করবো
            if (currentDistFrom != INT_MAX)
            {
                // relaxation step: নতুন path যদি ছোট হয় তাহলে update করবো
                if (currentDistFrom + weight < currentDistTo)
                {
                    distanceArr[toNode] = currentDistFrom + weight;
                }
            }
        }
    }
    // https://phitron.io/ph068/video/ph068-9_8-detect-negative-weighted-cycle-using-bellman-ford
    bool isCycle = false;
    // V-1 iteration এর পর আরও 1 বার check করি (extra iteration) | যদি কোনো edge এখনো relax করা যায়,
    // তাহলে graph-এ negative weight cycle আছে
    for (auto edge : edge_list)
    {
        int fromNode = edge.node;
        int toNode = edge.toNode;
        int weight = edge.cost;
        int currentDistFrom = distanceArr[fromNode];
        int currentDistTo = distanceArr[toNode];

        if (currentDistFrom != INT_MAX)
        {
            if (currentDistFrom + weight < currentDistTo)
            {
                isCycle = true;
            }
        }
    }
    // যদি negative cycle থাকে
    if (isCycle)
    {
        // negative cycle থাকলে shortest path valid না | not any output
        cout << "Negative weighted cycle detected\n";
    }
    else
    {
        // না থাকলে valid shortest distance print করবো
        for (int i = 0; i < totalNode; i++)
        {
            cout << i << " => " << distanceArr[i] << endl;
        }
    }
}
int main()
{

    cin >> totalNode >> totalEdge;
    while (totalEdge--)
    {
        int node, toNode, cost;
        cin >> node >> toNode >> cost;
        edge_list.push_back(Edge(node, toNode, cost));
        // edge_list.push_back(Edge(toNode, node, cost)); // when undirect graph
    };
    for (int nodeIdx = 0; nodeIdx < totalNode; nodeIdx++)
    {
        distanceArr[nodeIdx] = INT_MAX; // infinity
    }
    distanceArr[0] = 0; // source manual set
    bellman_ford();

    return 0;
}

/* https://prnt.sc/T75qD1mjrFEO
https://phitron.io/ph068/video/ph068-9_6-bellman-ford-animated
input:
4 4
0 2 5
0 3 12
2 1 2
1 3 3

output:
0 => 0
1 => 7
2 => 5
3 => 10


*/

/*
  🔥 Time Complexity Calculation:

  outer loop  → O(V)
  inner loop  → O(E)

  total = O(V × E)

  কারণ:
  - প্রতিটি iteration এ (V-1 বার)
  - আমরা সব edge (E) একবার করে check করি

  তাই overall complexity = O(V × E)

  ⚠️ Worst case এ Bellman-Ford slow হয়, especially dense graph এ

  Space Complexity:
  - distance array = O(V)
  - edge list = O(E)
  */