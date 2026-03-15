// Edge List Representation (Undirected Graph)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int totalNodes, totalEdges;
    cin >> totalNodes >> totalEdges;

    vector<pair<int, int>> edgeList;
    edgeList.reserve(totalEdges); // নিচের ব্যাখ্যা করা আছে

    for (int i = 0; i < totalEdges; i++)
    {
        int sourceNode, destinationNode; // 👈 Better names
        cin >> sourceNode >> destinationNode;

        edgeList.push_back({sourceNode, destinationNode});
    }

    cout << "Edge List:\n";
    for (auto edge : edgeList)
    {
        cout << edge.first << " -> " << edge.second << endl;
    }

    return 0;
}

/*
edgeList.reserve(totalEdges);

🔴 Without reserve()

ধরা যাক totalEdges = 1000

তুমি শুরুতে empty vector নিলে:

Capacity: 0
push → 1
push → 2
push → 4
push → 8
push → 16
push → 32
...

প্রতিবার capacity শেষ হলে vector দ্বিগুণ করে।

👉 ফলে বারবার copy হচ্ছে
👉 Time overhead হচ্ছে

✅ With reserve()
edgeList.reserve(totalEdges);

মানে:

👉 আগে থেকেই 1000 size জায়গা নিয়ে রাখো
👉 পরে push করলে আর reallocate লাগবে না

✔ Faster
✔ Efficient
✔ Especially বড় graph এ useful
*/