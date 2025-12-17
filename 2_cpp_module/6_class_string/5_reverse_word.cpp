#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    getline(cin, s); // input: Hello My Name Sampod
    stringstream ss(s);
    string word;
    ss >> word;
    reverse(word.begin(), word.end());
    cout << word;
    while (ss >> word)
    {
        reverse(word.begin(), word.end());
        cout << " " << word;
    }
    // output : olleH yM emaN dopmaS

    return 0;
}