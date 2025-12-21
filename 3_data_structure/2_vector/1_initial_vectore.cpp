#include <bits/stdc++.h>
// bits/stdc++.h → C++ এর প্রায় সব standard library একসাথে include করে
// Competitive programming এ খুব বেশি ব্যবহার হয়

using namespace std;
// std:: লিখতে না চাইলে namespace ব্যবহার করা হয়

int main()
{
    /*
    ===============================
    Vector কী?
    ===============================
    vector হলো dynamic array
    অর্থাৎ array এর মতো কিন্তু এর size রানটাইমে বাড়ানো / কমানো যায়
    */

    // vector<int> v;
    // 👉 Type 1: empty vector (initial size = 0)

    // vector<int> v(10);
    // 👉 Type 2: size 10 এর vector
    // 👉 default value হবে 0 → [0 0 0 0 0 0 0 0 0 0]

    // vector<int> v(10, -5);
    // 👉 Type 3: size 10 এবং প্রতিটা value = -5
    // 👉 output: [-5 -5 -5 -5 -5 -5 -5 -5 -5 -5]

    // vector<int> v = {1, 2, 3, 4};
    // 👉 Type 4: direct initialization (initializer list)

    /*
    ===============================
    Array থেকে Vector এ কপি
    ===============================
    */

    int a[5] = {1, 2, 3, 4, 5};
    // 👉 সাধারণ static array

    vector<int> v(a, a + 5);
    /*
    👉 এখানে:
       a       → array এর starting address
       a + 5   → array এর ending address (last element এর পরের জায়গা)

    👉 এইভাবে array এর সব element vector এ কপি হয়
    */

    for (int i = 0; i < v.size(); i++)
    {
        // v.size() → vector এ মোট কয়টা element আছে
        cout << v[i] << " ";
        // index ব্যবহার করে element access
    }

    return 0;
}
