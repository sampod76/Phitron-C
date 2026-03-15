#include <bits/stdc++.h>

using namespace std;
int main()
{
    int totalNode, totalEdges;
    cin >> totalNode >> totalEdges;
    //
    vector<vector<int>> adjacencyList(totalNode);
    while (totalEdges--)
    {
        int source, destination;
        cin >> source >> destination;
        //
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }
    for (int nodeIndex = 0; nodeIndex < totalNode; nodeIndex++)
    {
        cout << nodeIndex << " -connect-> ";

        for (int neighbor : adjacencyList[nodeIndex])
        {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    return 0;
}