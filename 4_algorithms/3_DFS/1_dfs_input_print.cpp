/*
DFS (Depth First Search) কি?
DFS (Depth First Search) হলো একটি graph traversal algorithm যা একটি node থেকে শুরু করে যত গভীরে যাওয়া যায় তত গভীরে যায়, তারপর আর যাওয়ার পথ না থাকলে backtrack করে অন্য পথে যায়।

সহজ ভাষায়:
DFS আগে গভীরে যায়, তারপর পাশের node গুলো explore করে।
*/
#include <bits/stdc++.h>

using namespace std;
vector<int> adj_list[1005];
bool visitedArr[1005];
void dfs(int src)
{
    // আলাদা করে base case দরকার নেই
    // কারণ যখন কোনো node এর আর unvisited child থাকবে না
    // তখন recursion নিজে থেকেই শেষ হয়ে যাবে
    cout << src << " ";
    visitedArr[src] = true;
    for (int child : adj_list[src])
    {
        if (!visitedArr[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int src, dist;
        cin >> src >> dist;
        adj_list[src].push_back(dist);
        adj_list[dist].push_back(src);
    }
    memset(visitedArr, false, sizeof(visitedArr));
    dfs(0);
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

output: 0 1 3 2 5 6 4

*/
