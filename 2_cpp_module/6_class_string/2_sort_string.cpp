#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin >> s;
    // first -- string start pointer/address and ending pointer/address
    sort(s.begin(), s.end()); // input:  ecdba
    cout << s << endl;        // output: abcde
    return 0;
}