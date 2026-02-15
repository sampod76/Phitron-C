#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string storeWorld;
    bool isFindName = false;
    while (ss >> storeWorld)
    {
        if (storeWorld == "Jessica")
        {
            isFindName = true;
            break;
        }
    }
    if (isFindName)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}