
// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
/*
input

5 5 4 6 4
*/

int main()
{
    int *a = new int[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << a[i] << " ";
    // }
    int *b = new int[5];
    for (int i = 0; i < 3; i++)
    {
        b[i] = a[i];
    }

    b[3] = 50;
    b[4] = 60;
    delete[] a; // array variable delete methord

    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}