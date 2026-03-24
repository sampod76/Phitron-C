#include <bits/stdc++.h>
using namespace std;

int main()
{

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int n;
        cin >> n;

        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        int maxHeight = INT_MIN;
        int secondMaxHeight = INT_MIN;

        int maxIndex = -1;
        int secondMaxIndex = -1;

        // find max
        for (int i = 0; i < n; i++)
        {
            if (heights[i] > maxHeight)
            {
                maxHeight = heights[i];
                maxIndex = i;
            }
        }

        // find second max
        for (int i = 0; i < n; i++)
        {
            if (i != maxIndex && heights[i] > secondMaxHeight)
            {
                secondMaxHeight = heights[i];
                secondMaxIndex = i;
            }
        }

        // print smaller index first
        if (maxIndex < secondMaxIndex)
        {
            cout << maxIndex << " " << secondMaxIndex << "\n";
        }
        else
        {
            cout << secondMaxIndex << " " << maxIndex << "\n";
        }
    }

    return 0;
}