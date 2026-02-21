#include <bits/stdc++.h>

using namespace std;
int main()
{
    list<int> l = {10, 20, 50, 30, 50, 30, 50, 90, 80, 50};
    // remove any value
    l.remove(50);
    l.sort();               // asc order
    l.sort(greater<int>()); // desc order
                            // l.unique();             // remove duplicate value , but only sorted value remove
    l.reverse();
    for (int value : l)
    {
        cout << value << " ";
    }
    return 0;
}