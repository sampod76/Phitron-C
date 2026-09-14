#include <bits/stdc++.h>
// https://phitron.io/ph068/video/ph068-2_8-single-source-shortest-distance-using-bfs
// অর্থাৎ একটি source node থেকে অন্য node পর্যন্ত যেতে
// সর্বনিম্ন কতটি edges/level লাগবে তা বের করা
// Level = Source থেকে কত edge দূরে
using namespace std;

vector<int> adj_list[1005]; // adjacency list -> প্রতিটি node এর সাথে কোন কোন node connected তা রাখা
bool visitedArr[1005];      // কোন node visited হয়েছে কিনা তা track করার জন্য
int level[1005];            // source node থেকে প্রতিটি node পর্যন্ত distance (level)

void bfs(int src)
{

    queue<int> nodeQueue;      // BFS এ queue ব্যবহার করা হয়
    nodeQueue.push(src);       // source node queue তে push
    visitedArr[src] = true;    // source node visited
    level[src] = 0;            // source থেকে source এর distance = 0
    while (!nodeQueue.empty()) // queue খালি না হওয়া পর্যন্ত loop চলবে
    {
        int currentNode = nodeQueue.front();    // queue এর front node বের করা
        nodeQueue.pop();                        // queue থেকে remove করা
        for (int child : adj_list[currentNode]) // current node এর সব child node iterate করা
        {
            if (!visitedArr[child]) // যদি child node আগে visit না হয়ে থাকে
            {
                nodeQueue.push(child);                 // child node queue তে add
                visitedArr[child] = true;              // child node visited mark
                level[child] = level[currentNode] + 1; // child এর level = parent level + 1
            }
        }
    }
};

int main()
{
    int totalNode, totalEdge;
    cin >> totalNode >> totalEdge; // মোট node এবং edge ইনপুট নেওয়া
    while (totalEdge--)            // edge input নেওয়া
    {
        int src, dist;
        cin >> src >> dist;
        // undirected graph
        // src -> dist connection
        adj_list[src].push_back(dist);
        // dist -> src connection
        adj_list[dist].push_back(src);
    }
    memset(visitedArr, false, sizeof(visitedArr)); // visited array false দিয়ে initialize
    memset(level, -1, sizeof(level));              // level array -1 দিয়ে initialize . মানে এখনো কোন node এর distance জানা নেই
    int src, dist;
    cin >> src >> dist; // source node এবং destination node ইনপুট
    // BFS run
    bfs(src);

    /*
    চাইলে সব node এর distance দেখতে পারো
    */
    for (int i = 0; i < totalNode; i++)
    {
        cout << i << " node --> level " << level[i] << endl;
    }

    // source থেকে destination এর shortest distance print
    cout << level[dist];

    return 0;
}

/*
7 9
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
0 6
0
6
*/