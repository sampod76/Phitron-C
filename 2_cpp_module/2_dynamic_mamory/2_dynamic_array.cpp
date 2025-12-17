// https://phitron.io/ph158/video/ph158-2_2-dynamic-variable
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
    int *a = new int[5]; // Dynamic array
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}