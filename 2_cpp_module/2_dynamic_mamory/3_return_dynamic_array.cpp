
#include <bits/stdc++.h>

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
int *fun()
{
    int *a = new int[5]; // dynamic array
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    return a;
}
int main()
{
    int *x = fun();
    for (int i = 0; i < 5; i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}