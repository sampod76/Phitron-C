#include <bits/stdc++.h>
using namespace std;

class MinMax
{
public:
    int minIndex;
    int maxIndex;
    // int value;
};
int main()
{
    int n;
    cin >> n;

    int a[n];
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > a[maxIndex])
        {
            maxIndex = i;
        }
        if (a[i] < a[minIndex])
        {
            minIndex = i;
        }
    }
    // cout << a[minIndex] << " " << a[maxIndex] << " ";
    swap(a[minIndex], a[maxIndex]);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
