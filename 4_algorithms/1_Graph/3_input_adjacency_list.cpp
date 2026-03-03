/*
Adjacency List কী?
Adjacency List হলো এমন একটি পদ্ধতি যেখানে:
প্রতিটি node এর সাথে যেসব node যুক্ত আছে, তাদের একটি list আকারে সংরক্ষণ করা হয়।
এটি Memory efficient (বিশেষ করে sparse graph এ)।
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    // 🔹 Adjacency List তৈরি
    // এখানে আমরা vector of array ব্যবহার করছি

    vector<int> adj_arr[node];
    // 🔹 Edge input নেওয়া
    for (int i = 0; i < edge; i++)
    {
        int r, c;
        cin >> r >> c;
        // r এর সাথে c যুক্ত
        adj_arr[r].push_back(c);
        // undirected graph হলে দুই দিকেই push করতে হয়
        adj_arr[c].push_back(r);
    }

    // 🔹 Graph print করা
    for (int i = 0; i < node; i++)
    {
        cout << i << " -connect-> ";
        for (int val : adj_arr[i])
        {
            cout << val << " ";
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