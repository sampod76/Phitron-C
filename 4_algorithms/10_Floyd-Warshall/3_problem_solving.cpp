#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph068/video/ph068-10_8-shortest-routes-ii-problem-link-https-cses-fi-problemset-task-1672-
// https://cses.fi/problemset/task/1672/
int main()
{
    int totalNode, totalEdge, totalQuery;
    cin >> totalNode >> totalEdge >> totalQuery;
    long long int adj_mat[totalNode + 1][totalNode + 1]; // because 1 base index
    //
    for (int row = 1; row <= totalNode; row++)
    {
        for (int col = 1; col <= totalNode; col++)
        {
            if (row == col)
            {
                adj_mat[row][col] = 0;
            }
            else
            {
                adj_mat[row][col] = LLONG_MAX;
            }
        }
    }

    while (totalEdge--)
    {
        long long int node, toNode, cost;
        cin >> node >> toNode >> cost;
        adj_mat[node][toNode] = min(adj_mat[node][toNode], cost);
        adj_mat[toNode][node] = min(adj_mat[toNode][node], cost); // undirected graph

        /*
        // যদি একই দুইটি node এর মধ্যে একাধিক edge থাকে (যেমন: 0→3 = 5, আবার 0→3 = 1),
        // তাহলে প্রথমবার একটি value set হবে, পরবর্তীতে নতুন edge আসলে আগের value এর সাথে compare করে দেখব কোনটি ছোট।
        // তাই আমরা সবসময় minimum cost (shortest edge) রেখে দিই।
         */
    }

    for (int midNode = 1; midNode <= totalNode; midNode++)
    {
        for (int fromNode = 1; fromNode <= totalNode; fromNode++)
        {
            for (int toNode = 1; toNode <= totalNode; toNode++)
            {
                // https://prnt.sc/8BRsVawC1sNN
                //  direct distance (from -> to)
                long long int directCost = adj_mat[fromNode][toNode];

                // split into two parts: (from -> mid) + (mid -> to)
                long long int costFrom_To_Mid = adj_mat[fromNode][midNode];
                long long int costMid_To_To = adj_mat[midNode][toNode];

                // যদি দুইটাই valid path হয় (∞ না হয়)
                if (costFrom_To_Mid != LLONG_MAX && costMid_To_To != LLONG_MAX)
                {
                    long long int newCost = costFrom_To_Mid + costMid_To_To;

                    // যদি নতুন path ছোট হয়
                    if (newCost < directCost)
                    {
                        adj_mat[fromNode][toNode] = newCost;
                    }
                }
            }
        }
    }

    while (totalQuery--)
    {
        int src, dist;
        cin >> src >> dist;
        if (adj_mat[src][dist] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[src][dist] << endl;
    }

    return 0;
}

/* https://phitron.io/ph068/video/ph068-10_8-shortest-routes-ii-problem-link-https-cses-fi-problemset-task-1672-
https://prnt.sc/8BRsVawC1sNN
input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2


//output
5
5
8
-1
3

*/