#include <bits/stdc++.h>

using namespace std;

int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge;
    //
    int adjacencyMatrix[totalNode][totalNode];
    memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));
    //

    while (totalEdge--)
    {
        int source, direction;
        cin >> source >> direction;
        //
        adjacencyMatrix[source][direction] = 1;
    }
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++)
    {
        int src, dist;
        cin >> src >> dist;
        //
        if (src == dist)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (adjacencyMatrix[src][dist] == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
// https://www.hackerrank.com/contests/a1-algorithm-b8/challenges/connected-or-not-1-1
/* input:
5 6
0 1
1 2
2 3
3 4
1 4
0 2
10
0 1
1 0
2 2
2 3
0 3
3 0
1 4
4 1
4 3
1 2

//output

YES
NO
YES
YES
NO
NO
YES
NO
NO
YES

*/