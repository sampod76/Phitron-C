#include <bits/stdc++.h>

using namespace std;
// https://prnt.sc/oOT1hq9m8TUq
vector<pair<int, int>> adj_list[105];
int distanceArr[105];
// https://phitron.io/ph068/video/ph068-7_6-dijkstra-naive-implementation
void dijkstra(int srcNode)
{
    // -----------------------------------------
    // এই queue তে আমরা এমন pair রাখবো:
    // {node, source থেকে ওই node পর্যন্ত current shortest distance}
    // -----------------------------------------
    queue<pair<int, int>> nodeQueue;
    // source node থেকে source node এর distance = 0
    distanceArr[srcNode] = 0;
    // source node কে queue তে ঢুকিয়ে traversal শুরু করছি
    nodeQueue.push({srcNode, 0});
    // queue খালি না হওয়া পর্যন্ত একের পর এক node process করবো
    while (!nodeQueue.empty())
    {
        // সামনে থাকা node বের করছি
        pair<int, int> current = nodeQueue.front();
        nodeQueue.pop();
        // current node
        int currentNode = current.first;
        // source থেকে current node পর্যন্ত এখন পর্যন্ত পাওয়া distance
        int currentDistance = current.second;
        // current node এর সব adjacent node / neighbor ঘুরে দেখছি
        for (pair<int, int> child : adj_list[currentNode])
        {
            // neighbor node
            int child_node = child.first;
            // current node থেকে neighbor node এ যাওয়ার weight
            int child_weight = child.second;

            // -----------------------------------------
            // Relaxation:
            // source -> currentNode -> child_node
            // এই নতুন path যদি আগের stored path থেকে ছোট হয়,
            // তাহলে distance update করবো
            // -----------------------------------------
            if (currentDistance + child_weight < distanceArr[child_node])
            {
                // নতুন ছোট distance store করে দিচ্ছি
                distanceArr[child_node] = currentDistance + child_weight;
                // distance update হয়েছে, তাই এই neighbor node কে আবার queue তে নিচ্ছি , যেন এর neighbor গুলোও পরে check করা যায়
                nodeQueue.push({child_node, currentDistance + child_weight});
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
        // https://prnt.sc/35FLzPvgOsBS
        int srcNode, distNode, weight; // src to dist node =>cost/weight
        cin >> srcNode >> distNode >> weight;
        adj_list[srcNode].push_back({distNode, weight});
        adj_list[distNode].push_back({srcNode, weight}); // when undirected graph other wise comment
    }
    // memset(dis,INT_MAX,sizeof(dis)); // it is not work INT_MAX
    for (int node = 0; node < totalNode; node++)
    {
        distanceArr[node] = INT_MAX;
    }
    dijkstra(0);
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