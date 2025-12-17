#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[100001];
    while (cin.getline(s, 100001))
    {
        int sLength = strlen(s);
        sort(s, s + sLength);
        for (int i = 0; i < sLength; i++)
        {
            if (s[i] != ' ')
            {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}