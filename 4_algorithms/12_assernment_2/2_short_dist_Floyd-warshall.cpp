#include <bits/stdc++.h>

using namespace std;
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    long long int adj_mat[totalNode + 1][totalNode + 1];
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
    }

    for (int midNode = 1; midNode <= totalNode; midNode++)
    {
        for (int fromNode = 1; fromNode <= totalNode; fromNode++)
        {
            for (int toNode = 1; toNode <= totalNode; toNode++)
            {
                long long int directCost = adj_mat[fromNode][toNode];
                long long int costFrom_To_Mid = adj_mat[fromNode][midNode];
                long long int costMid_To_toNode = adj_mat[midNode][toNode];
                //
                if (costFrom_To_Mid != LLONG_MAX && costMid_To_toNode != LLONG_MAX)
                {
                    long long int newCost = costFrom_To_Mid + costMid_To_toNode;
                    if (newCost < directCost)
                    {
                        adj_mat[fromNode][toNode] = newCost;
                    }
                }
            }
        }
    }
    int totalQuery;
    cin >> totalQuery;
    while (totalQuery--)
    {
        int src, dist;
        cin >> src >> dist;
        if (adj_mat[src][dist] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj_mat[src][dist] << endl;
        }
    }

    return 0;
}