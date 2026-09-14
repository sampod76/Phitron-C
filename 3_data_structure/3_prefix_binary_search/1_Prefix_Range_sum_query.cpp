// module dsa- > 3_4 Range Sum Query prefix sum solution II
// https://phitron.io/ph048/video/ph048-3_4-range-sum-query-prefix-sum-solution-ii
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // n = array এর size
    // q = কয়টা query আছে
    int n, q;
    cin >> n >> q;

    // array A (১-based index ব্যবহার করবো)
    // তাই size n+1 নিলাম
    vector<long long int> arr(n + 1);

    // array input নিচ্ছি
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    // prefix sum array
    // pre[i] = index 1 থেকে i পর্যন্ত সব element এর যোগফল
    vector<long long int> pre(n + 1);

    // প্রথম element এর prefix sum
    pre[1] = arr[1];

    // prefix sum তৈরি
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }

    // এখন query গুলো প্রসেস করবো
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        long long int sum;

        // যদি range শুরু হয় 1 থেকে
        if (l == 1)
        {
            sum = pre[r];
        }
        // নাহলে prefix formula ব্যবহার
        else
        {
            sum = pre[r] - pre[l - 1];
        }

        // result print
        cout << sum << endl;
    }

    return 0;
}

/*
🔹 সমস্যাটা আসলে কী?

তোমার কাছে আছে:

একটি array

বারবার প্রশ্ন করা হচ্ছে:

“এই array-এর L থেকে R পর্যন্ত অংশের যোগফল কত?”

👉 একবার নয়, অনেকবার (Q বার)

🔹 আমরা স্বাভাবিকভাবে কী করি?

প্রথমে মাথায় যেটা আসে:

“L থেকে R পর্যন্ত লুপ চালিয়ে যোগ করে দিই”

sum = 0;
for(i = L; i <= R; i++)
    sum += A[i];

🤔 সমস্যা কোথায়?

একটা query → ঠিক আছে

কিন্তু যদি:

N = 100000
Q = 100000


👉 তাহলে 10¹⁰ অপারেশন 😱
এইখানেই Prefix Sum দরকার

🔹 চিন্তার মোড় ঘোরানোর জায়গা

এখন প্রশ্ন করি:

“আমি কি প্রতিবার নতুন করে যোগ না করে
আগেই কিছু হিসাব করে রাখতে পারি?”

👉 এখান থেকেই Prefix Sum-এর ধারণা আসে

🔹 Prefix Sum কীভাবে ভাববো?

ধরো:

A = [6, 4, 2, 7, 2, 7]


আমি যদি নিজেকে বলি:

“index 1 থেকে যতদূর পর্যন্ত যোগফল দরকার,
আমি সেটা আগেই বের করে রাখবো”

তাহলে বানাই:

pre[i] = 1 থেকে i পর্যন্ত যোগফল

Prefix Array হবে:
Index:   1   2   3   4   5   6
A:       6   4   2   7   2   7
pre:     6  10  12  19  21  28

🔹 এখন ম্যাজিক কোথায়?

ধরো প্রশ্ন:

L = 3, R = 6

আমাদের দরকার:

A[3] + A[4] + A[5] + A[6]


কিন্তু আমাদের কাছে আছে:

pre[6] = A[1] + A[2] + A[3] + A[4] + A[5] + A[6]
pre[2] = A[1] + A[2]


👉 তাহলে কী করলে বাকি অংশটা থাকবে?

pre[6] - pre[2]


🎯 এটাই Prefix Sum-এর মূল আইডিয়া

🔹 Formula নিজের মতো করে ভাবো
sum(L → R) = pre[R] - pre[L - 1]

Special Case:
L = 1 হলে
sum = pre[R]


কারণ তখন কিছু বাদ দিতে হবে না

🔹 কেন এটা এত দ্রুত?
ধাপ	কাজ	সময়
1	Prefix array বানানো	O(N)
2	প্রতিটি query	O(1)

👉 হাজার হাজার query হলেও কোনো সমস্যা নেই

🔹 কীভাবে চিন্তা করলে নিজে Prefix Sum বের করতে পারবে?

নিজেকে এই ৩টা প্রশ্ন করো:

1️⃣ একই টাইপের যোগফল কি বারবার চাওয়া হচ্ছে?
2️⃣ আগে থেকে cumulative হিসাব রেখে দিলে কি সুবিধা হবে?
3️⃣ একটা query কি দুইটা pre value দিয়ে বের করা যায়?

যদি হ্যাঁ হয় → Prefix Sum

*/