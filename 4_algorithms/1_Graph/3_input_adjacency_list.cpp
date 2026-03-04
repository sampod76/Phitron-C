/*
Adjacency List কী?
Adjacency List হলো এমন একটি পদ্ধতি যেখানে:
প্রতিটি node এর সাথে যেসব node যুক্ত আছে, তাদের একটি list আকারে সংরক্ষণ করা হয়।
এটি Memory efficient (বিশেষ করে sparse graph এ)।
*/
#include <bits/stdc++.h>
using namespace std;
/*
Source : যে node থেকে connection শুরু হয়।
Destination: যে node-এ connection যায়।
*/
int main()
{
    int totalNodes, totalEdges;
    cin >> totalNodes >> totalEdges;

    // 🔹 Adjacency List তৈরি
    vector<int> adjacencyList[totalNodes];

    // 🔹 Edge input নেওয়া
    for (int i = 0; i < totalEdges; i++)
    {
        int source, destination;
        cin >> source >> destination;

        // source এর সাথে destination যুক্ত
        adjacencyList[source].push_back(destination);

        // undirected graph হলে দুই দিকেই push করতে হয়
        adjacencyList[destination].push_back(source);
    }

    // 🔹 Graph print করা
    for (int nodeIndex = 0; nodeIndex < totalNodes; nodeIndex++)
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

/*
input:
5 5
0 1
0 2
3 0
1 3
3 4

output:
0 -connect-> 1 2 3
1 -connect-> 0 3
2 -connect-> 0
3 -connect-> 0 1 4
4 -connect-> 3

*/