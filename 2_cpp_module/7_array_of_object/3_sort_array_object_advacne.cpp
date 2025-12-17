#include <bits/stdc++.h>
using namespace std;
/* input
5
Asif 29 95 2
Sakib 55 89 3
Zubair 57 93 1
Ahsan 39 89 3
Joy 12 99 2

*/
/*
Class (ascending) → ছোট ক্লাস আগে
Marks (descending) → ক্লাস একই হলে বেশি মার্ক আগে
Roll (ascending) → মার্কসও সমান হলে যার রোল ছোট, সে আগে
Sort by: class ASC → marks DESC → roll ASC
*/

/*
এখন Comparator-এর কাজ হলো —
👉 a এবং b — দুইজন স্টুডেন্টকে compare করা
👉 সিদ্ধান্ত নিতে হবে — a কি b-এর আগে আসবে?

Comparator লেখার সহজ নিয়ম:
--------------------------------------
❶ প্রথমে সবচেয়ে গুরুত্বপূর্ণ কন্ডিশন চেক করো (class)
❷ কন্ডিশনের ভেতরে ঢুকো যদি দুজন একই ক্লাসে হয়
❸ এরপর marks তুলনা করো
❹ তাও একই হলে roll তুলনা করো
--------------------------------------
*/
class Student
{
public:
    string name;
    int cls, roll, marks;
};
bool cam(Student a, Student b)
{

    if (a.cls == b.cls) // 1. class সমান
    {
        if (a.marks == b.marks)
        {
            // return a.roll < b.roll;
            if (a.roll < b.roll)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            // return a.marks > b.marks;
            if (a.roll > b.roll)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        // return a.cls < b.cls;
        if (a.cls < b.cls)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    Student a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].roll >> a[i].marks >> a[i].cls;
    }
    sort(a, a + n, cam);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].name << a[i].roll << a[i].marks << a[i].cls;
    }
    return 0;
}