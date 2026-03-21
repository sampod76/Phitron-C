#include <bits/stdc++.h>

using namespace std;

// https://phitron.io/ph068/video/ph068-7_4-dijkstra-naive-approach
// full concept:  https://prnt.sc/WLasa-lV78jW
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    // https://res.cloudinary.com/dqvhxpu11/image/upload/v1774029372/waight_marict_kddwkt.png // when store adj_matic => 2d grid
    // https://prnt.sc/vSvC1k2X7uJ9

    vector<pair<int, int>> adj_list[totalNode];
    while (totalEdge--)
    {
        // https://prnt.sc/35FLzPvgOsBS
        int srcNode, distNode, weight; // src to dist node =>cost/weight
        cin >> srcNode >> distNode >> weight;
        adj_list[srcNode].push_back({distNode, weight});
        adj_list[distNode].push_back({srcNode, weight}); // when undirected graph other wise comment
    }
    for (int node = 0; node < totalNode; node++)
    {

        cout << node << " => ";
        for (pair<int, int> nodePair : adj_list[node])
        {
            cout << nodePair.first << " " << nodePair.second << ", ";
            // output: https://prnt.sc/BfdNdqRfhqcG
        }
        cout << endl;
    }

    return 0;
}

/* input
5 8
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5

*/