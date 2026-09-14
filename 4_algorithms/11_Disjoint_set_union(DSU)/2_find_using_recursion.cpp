

#include <bits/stdc++.h>
using namespace std;
// https://phitron.io/ph068/video/ph068-11_3-find-operation-implementation
/*
    Disjoint Set (DSU) - Find with Path Compression

    Time Complexity:
    - Amortized: প্রায় O(1)
    - Worst: O(N) (but compression এর কারণে rare)

    Concept:
    - প্রত্যেক node তার parent কে point করে
    - যার parent = -1, সে leader/root
*/

int parentArr[1005];

// ------------------------------
// Find operation (Path Compression)
// ------------------------------

int findLeader(int node)
{
    // যদি parent -1 হয়, তাহলে এটা root/leader
    if (parentArr[node] == -1)
        return node;

    // recursion করে ultimate leader বের করি
    int leader = findLeader(parentArr[node]);

    // path compression:
    // ভবিষ্যতে দ্রুত access এর জন্য direct leader এ connect করে দেই
    // https://phitron.io/ph068/video/ph068-11_4-find-operation-optimized
    parentArr[node] = leader;

    return leader;
}

int main()
{
    // সব node এর parent initially -1
    memset(parentArr, -1, sizeof(parentArr));

    /*
        Example structure:
        0 → 1
        2 → 1
        3 → 1
        4 → 5 → 3 → 1

        Leader = 1
    */

    parentArr[0] = 1;
    parentArr[1] = -1;
    parentArr[2] = 1;
    parentArr[3] = 1;
    parentArr[4] = 5;
    parentArr[5] = 3;

    // ------------------------------
    // Output: leader of each node
    // ------------------------------
    for (int node = 0; node < 6; node++)
    {
        // cout << node << " leader => " << findLeader(node) << endl;
        cout << node << " leader => " << findLeader(node) << endl;
    }

    return 0;
}
