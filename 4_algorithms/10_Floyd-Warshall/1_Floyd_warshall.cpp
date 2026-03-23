#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph068/video/ph068-10_4-floyd-warshall-implementation
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    int adj_mat[totalNode][totalNode];
    //
    for (int row = 0; row < totalNode; row++)
    {
        for (int col = 0; col < totalNode; col++)
        {
            if (row == col)
            {
                adj_mat[row][col] = 0;
            }
            else
            {
                adj_mat[row][col] = INT_MAX;
            }
        }
    }
    while (totalEdge--)
    {
        int node, toNode, cost;
        cin >> node >> toNode >> cost;
        adj_mat[node][toNode] = cost;
        // adj_mat[toNode][node]=cost; // undirected graph
    }

    for (int midNode = 0; midNode < totalNode; midNode++)
    {
        for (int fromNode = 0; fromNode < totalNode; fromNode++)
        {
            for (int toNode = 0; toNode < totalNode; toNode++)
            {
                // https://prnt.sc/8BRsVawC1sNN
                //  direct distance (from -> to)
                int directCost = adj_mat[fromNode][toNode];

                // split into two parts: (from -> mid) + (mid -> to)
                int costFrom_To_Mid = adj_mat[fromNode][midNode];
                int costMid_To_To = adj_mat[midNode][toNode];

                // যদি দুইটাই valid path হয় (∞ না হয়)
                if (costFrom_To_Mid != INT_MAX && costMid_To_To != INT_MAX)
                {
                    int newCost = costFrom_To_Mid + costMid_To_To;

                    // যদি নতুন path ছোট হয়
                    if (newCost < directCost)
                    {
                        adj_mat[fromNode][toNode] = newCost;
                    }
                }
            }
        }
    }

    for (int row = 0; row < totalNode; row++)
    {
        for (int col = 0; col < totalNode; col++)
        {
            if (adj_mat[row][col] == INT_MAX)
            {
                cout << "∞ "; // infinity
            }
            else
            {
                cout << adj_mat[row][col] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
/*
    Time Complexity: O(V^3)

    কারণ:
    Floyd-Warshall algorithm এ 3টা nested loop থাকে:
    1. midNode (intermediate node)
    2. fromNode (source)
    3. toNode (destination)

    তাই total operations ≈ V × V × V = O(V^3)

    Space Complexity: O(V^2)
    কারণ adjacency matrix ব্যবহার করা হয়েছে
*/

/* https://phitron.io/ph068/video/ph068-10_4-floyd-warshall-implementation
https://prnt.sc/8BRsVawC1sNN
input:
4 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4


//output
0 3 5 8
∞ 0 2 5
∞ ∞ 0 4
∞ ∞ ∞ 0

*/