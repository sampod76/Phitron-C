#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string mainString;
        string findString;
        cin >> mainString >> findString;

        int idx = mainString.find(findString);
        while (idx != -1)
        {
            /* code */
            mainString.replace(idx, findString.length(), "#");
            idx = mainString.find(findString, idx + 1);
        }

        cout << mainString
             << endl;
    }

    return 0;
}