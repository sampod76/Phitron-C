#include <bits/stdc++.h>
using namespace std;
// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-08/challenges/water-4-1
// নিচে বেস্ট সলিউশন দেওয়া আছে
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

/* h = [5, 1, 5, 1, 5] যদি বিষয়টা এরকম হয় বেলুগুলো ইউনিক না হয় সে ক্ষেত্রে উপর একটা কাজ করবে না
https://chatgpt.com/share/69c30f26-8fb4-8000-a626-f290e1e7e92a
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Fast input-output (competitive programming এ useful)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases; // কতগুলো test case আছে

    while (testCases--)
    {
        int n;
        cin >> n; // array size

        // height গুলো রাখার জন্য vector
        vector<int> heights(n);

        // input নেওয়া
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        // Two pointer শুরু
        int left = 0;         // শুরু থেকে
        int right = n - 1;    // শেষ থেকে

        long long maxArea = 0; // এখন পর্যন্ত maximum area
        int bestLeft = 0, bestRight = 0; // best index pair

        // যতক্ষণ left < right, ততক্ষণ pair check করবো
        while (left < right)
        {
            // width = দুই index এর দূরত্ব
            long long width = right - left;

            // height = দুই পাশের মধ্যে ছোটটা (কারণ পানি ছোট দিকেই সীমাবদ্ধ)
            long long height = min(heights[left], heights[right]);

            // current container area
            long long currentArea = width * height;

            // যদি নতুন area বড় হয়, update করি
            if (currentArea > maxArea)
            {
                maxArea = currentArea;
                bestLeft = left;
                bestRight = right;
            }

            // 🔥 Main logic:
            // যেই পাশের height ছোট, সেটাকে move করি
            // কারণ ছোট height bottleneck তৈরি করে
            if (heights[left] < heights[right])
            {
                left++;  // ছোট height → left বাড়াই
            }
            else
            {
                right--; // ছোট height → right কমাই
            }
        }

        // result print (index pair)
        cout << bestLeft << " " << bestRight << "\n";
    }

    return 0;
}
*/