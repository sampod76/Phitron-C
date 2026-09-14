#include <bits/stdc++.h>

using namespace std;
// https://www.hackerrank.com/contests/a1-algorithm-b8/challenges/connected-nodes-1
int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    vector<int> adj_list[totalNode];
    //
    while (totalEdge--)
    {
        int src, dist;
        cin >> src >> dist;
        //
        adj_list[src].push_back(dist);
        adj_list[dist].push_back(src);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int distIdx;
        cin >> distIdx;
        if (adj_list[distIdx].size() == 0)
        {
            cout << -1;
            cout << endl;
        }
        else
        {

            sort(adj_list[distIdx].begin(), adj_list[distIdx].end(), greater<int>());
            for (int child : adj_list[distIdx])
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/* // input
6 8
0 4
0 5
4 2
4 3
5 3
2 0
0 1
1 3
6
0
1
2
3
4
5

//output
5 4 2 1
3 0
4 0
5 4 1
3 2 0
3 0
*/