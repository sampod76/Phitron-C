#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph068/video/ph068-2_10-path-printing-implementation
// কোন নির্দিষ্ট source node থেকে destination node পর্যন্ত যাওয়ার সময় যে shortest path-এর node গুলো পড়ে, সেগুলো প্রিন্ট করা।
#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[1005]; // adjacency list -> কোন node এর সাথে কোন node connected
bool visitedArr[1005];      // node visited হয়েছে কিনা check করার জন্য
int level[1005];            // source থেকে node পর্যন্ত distance
int parentArr[1005];        // path বের করার জন্য parent store

void bfs(int src)
{
    queue<int> sQueue;      // BFS এর জন্য queue
    sQueue.push(src);       // source node queue তে push
    visitedArr[src] = true; // source visited
    level[src] = 0;         // source level = 0

    while (!sQueue.empty())
    {
        int par = sQueue.front(); // queue এর সামনে থাকা node নেওয়া
        sQueue.pop();             // queue থেকে remove

        for (int child : adj_list[par]) // current node এর সব neighbour traverse
        {
            if (!visitedArr[child]) // যদি child আগে visit না হয়ে থাকে
            {
                visitedArr[child] = true;      // visited mark
                level[child] = level[par] + 1; // parent level + 1 = child level
                parentArr[child] = par;        // child এর parent store
                sQueue.push(child);            // child queue তে push
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e; // node এবং edge ইনপুট

    while (e--)
    {
        int s, d;
        cin >> s >> d; // edge input

        adj_list[s].push_back(d); // s -> d connection
        adj_list[d].push_back(s); // undirected graph তাই reverse connection
    }

    memset(visitedArr, false, sizeof(visitedArr)); // visited false দিয়ে initialize
    memset(level, 0, sizeof(level));               // level initialize
    memset(parentArr, -1, sizeof(parentArr));      // parent -1 দিয়ে initialize

    int src, dist;
    cin >> src >> dist; // source এবং destination

    bfs(src);              // BFS run
    vector<int> pathV;     // path store করার vector
    int tempNode = dist;   // destination থেকে path build শুরু
    while (tempNode != -1) // parent -1 না হওয়া পর্যন্ত চলবে
    {
        pathV.push_back(tempNode);      // current node store
        tempNode = parentArr[tempNode]; // parent node এ যাওয়া
    }

    reverse(pathV.begin(), pathV.end()); // path reverse (src → dest order করার জন্য)

    for (int val : pathV)
    {
        cout << val << " "; // final path print
    }

    return 0;
}

/*
input: https://prnt.sc/4KOZkaBLHBLt
7 7
0 1
1 3
3 2
1 4
3 5
2 5
5 6

0
6

output:
0 --> ar --parent--> -1
1 --> ar --parent--> 0
2 --> ar --parent--> 3
3 --> ar --parent--> 1
4 --> ar --parent--> 1
5 --> ar --parent--> 6
6 --> ar --parent--> 0

*/