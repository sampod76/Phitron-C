#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph068/video/ph068-10_6-detect-negative-weighted-cycle-using-floyd-warshall
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

    // কোনো node থেকে নিজের কাছেই যাওয়ার cost সাধারণত 0 থাকে। কিন্তু যদি Floyd-Warshall algorithm চালানোর পরে দেখা যায় adj_mat[i][i] < 0 = -value (negative value), তাহলে বুঝতে হবে গ্রাফে একটি negative weight cycle আছে
    bool isCycle = false;
    for (int i = 0; i < totalNode; i++)
    {
        if (adj_mat[i][i] < 0) // adj_mat[i][j] same row / same col
        {
            isCycle = true;
        }
    }
    if (isCycle)
    {
        cout << " Negative weighted cycle detected";
    }
    else
    {

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
    }

    return 0;
}

/* https://phitron.io/ph068/video/ph068-10_6-detect-negative-weighted-cycle-using-floyd-warshall
// https://prnt.sc/U_nQtCg-DTXB
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