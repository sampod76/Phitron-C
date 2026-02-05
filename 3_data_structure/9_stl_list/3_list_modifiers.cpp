#include <bits/stdc++.h>

using namespace std;
int main()
{
    list<int> l = {10, 20, 50, 30, 50, 30, 50, 90, 80, 50};
    list<int> l2;
    l2 = l;
    // or-> l2.assign(l.begin(), l.end());
    l2.push_back(60);
    l2.push_front(50);
    l2.pop_back();
    l2.pop_front();
    // l2.begin() → লিস্টের প্রথম এলিমেন্টের iterator রিটার্ন করে | next(l2.begin(), 2) → প্রথম এলিমেন্ট থেকে 2 ধাপ সামনে গিয়ে যে iterator পাওয়া যায়
    // অর্থাৎ index = 2 (0-based হিসেবে)
    auto index = next(l2.begin(), 2);
    // insert(index, 500) → index যেই জায়গা নির্দেশ করছে, তার আগেই 500 ভ্যালুটা insert হবে
    l2.insert(index, 500);
    list<int> l3 = {121, 320, 254};
    l2.insert(index, l3.begin(), l3.end());
    // erase
    auto eraseIndex = next(l2.begin(), 3);
    l2.erase(eraseIndex);
    //
    auto eraseStartIndex = next(l2.begin(), 2);
    auto eraseEndIndex = next(l2.begin(), 5);
    l2.erase(eraseStartIndex, eraseEndIndex);
    // replace-> find all 50 and replace 19
    replace(l2.begin(), l2.end(), 50, 19);

    for (int value : l2)
    {
        cout << value << " ";
    }
    // isExist --> find
    auto isExitIt = find(l2.begin(), l2.end(), 66);
    if (isExitIt == l2.end())
    {
        cout << "Not exist";
    }
    else
    {
        cout << "exist";
    }

    return 0;
}