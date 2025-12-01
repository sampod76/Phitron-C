#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin >> s;
    // first -- string start pointer/address and ending pointer/address
    reverse(s.begin(), s.end()); // input:  ecdba
    cout << s << endl;           // output: abdce
    int a[4] = {5, 6, 2, 9};
    reverse(a, a + 4);
    for (int c : a)
    {
        cout << c << " ";
    }
    // output : 9 2 6 5
    return 0;
}