#include <bits/stdc++.h>
using namespace std;
// https://phitron.io/ph068/video/ph068-7_12-dijkstra-optimized-implementation
// Adjacency List:
// adj_list[u] = vector of {v, weight}
// মানে u থেকে কোন কোন node এ যাওয়া যায় এবং কত cost লাগে
vector<pair<int, int>> adj_list[105];

// distanceArr[i] = source থেকে node i পর্যন্ত shortest distance
int distanceArr[105];

// -----------------------------------------
// Dijkstra Algorithm (Using Min Heap)
// -----------------------------------------
//? time complexity: https://phitron.io/ph068/video/ph068-7_13-complexity-of-dijkstra-optimized
void dijkstra(int srcNode)
{
    // priority queue (Min Heap)
    // এখানে pair রাখা হচ্ছে: {distance, node}
    // সবসময় smallest distance আগে বের হবে
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        nodeQueue;

    // source node এর distance = 0
    distanceArr[srcNode] = 0;

    // শুরুতে source node queue তে push
    nodeQueue.push({0, srcNode});

    // যতক্ষণ queue খালি না হয়, ততক্ষণ process চলবে
    while (!nodeQueue.empty())
    {
        // queue এর top element (smallest distance)
        pair<int, int> current = nodeQueue.top();
        nodeQueue.pop();

        int currentDistance = current.first; // source → currentNode distance
        int currentNode = current.second;    // current node

        // ⚠️ Important Optimization:
        // যদি এই node এর জন্য already better distance পাওয়া থাকে,
        // তাহলে এই iteration skip করবো (outdated entry)
        if (currentDistance > distanceArr[currentNode])
            continue;

        // currentNode এর সব neighbor ঘুরে দেখা
        for (pair<int, int> child : adj_list[currentNode])
        {
            int child_node = child.first;    // neighbor node
            int child_weight = child.second; // edge weight

            // -----------------------------------------
            // Relaxation Step:
            // source → currentNode → child_node
            // নতুন distance যদি ছোট হয়, update করবো
            // -----------------------------------------
            if (currentDistance + child_weight < distanceArr[child_node])
            {
                // distance update
                distanceArr[child_node] = currentDistance + child_weight;

                // নতুন updated distance নিয়ে queue তে push
                // যাতে future এ এর neighbor গুলো check করা যায়
                nodeQueue.push({distanceArr[child_node], child_node});
            }
        }
    }
}

int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;

    // graph input নেওয়া
    while (totalEdge--)
    {
        int srcNode, distNode, weight;
        cin >> srcNode >> distNode >> weight;

        // undirected graph
        adj_list[srcNode].push_back({distNode, weight});
        adj_list[distNode].push_back({srcNode, weight});
    }

    // শুরুতে সব node এর distance infinite ধরা হচ্ছে
    for (int node = 0; node < totalNode; node++)
    {
        distanceArr[node] = INT_MAX;
    }

    // source = 0 ধরে Dijkstra চালানো
    dijkstra(0);

    // output print
    for (int i = 0; i < totalNode; i++)
    {
        cout << i << " => " << distanceArr[i] << endl;
    }

    return 0;
}

/*input : https://prnt.sc/oOT1hq9m8TUq
5 8
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5

output:
0 => 0
1 => 6
2 => 5
3 => 4
4 => 9

 */