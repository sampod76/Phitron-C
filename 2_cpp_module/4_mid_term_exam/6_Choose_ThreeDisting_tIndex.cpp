#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // কতগুলো test case আছে
    cin >> t;

    while (t--)
    { // প্রতিটা test case চালাবো

        int n, sum; // n = array-এর আকার, sum = target sum
        cin >> n >> sum;

        int a[n]; // array declare

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool isMatch = false; // ধরি এখনো কোন 3 number-এর sum পাওয়া যায়নি

        //! তিনটি nested loop → তিনটি আলাদা index নির্বাচন করার জন্য |কারো তোমাকে প্রশ্নই বলা হয়েছে (তিনটা ইউনিক কম্বিনেশন ) তাই তিনবার nested loop চলেছে, যদি চারটা বলতো তাহলে চারটা nested loop চালানো হতো
        for (int i = 0; i < n; i++)
        { // প্রথম index
            for (int j = i + 1; j < n; j++)
            { // দ্বিতীয় index (i এর পর থেকে)
                for (int k = j + 1; k < n; k++)
                { // তৃতীয় index (j এর পর থেকে)

                    int total = a[i] + a[j] + a[k]; // তিনটার যোগফল

                    if (total == sum)
                    {                   // যদি target sum পাই
                        isMatch = true; // flag true করে দেই
                    }
                }
            }
        }

        if (isMatch)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
