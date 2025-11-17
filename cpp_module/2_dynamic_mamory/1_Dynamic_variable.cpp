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
int *p;
void fun()
{
    int *x = new int;
    *x = 900;
    p = x; // jast save pointer/address not value
    cout << "FUN -> " << *p << endl;
}
int main()
{
    fun();
    cout << "Main --> " << *p << endl;
    return 0;
}