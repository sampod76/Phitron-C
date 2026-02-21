#include <bits/stdc++.h>

using namespace std;
int getSum(stack<int> s)
{
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    return sum;
};
int main()
{
    stack<int> st1, st2, st3;

    // Stack 1
    st1.push(8);
    st1.push(5);
    st1.push(3);

    // Stack 2
    st2.push(2);
    st2.push(2);
    st2.push(4);
    st2.push(9);
    st2.push(6);

    // Stack 3
    st3.push(2);
    st3.push(1);
    st3.push(2);
    st3.push(3);
    int sum1 = getSum(st1);
    int sum2 = getSum(st2);
    int sum3 = getSum(st3);
    while (true)
    { //

        if (sum1 == sum2 && sum2 == sum3)
        {
            break;
        }
        /*
এটি সিরিয়াল (st1 → st2 → st3) অনুযায়ী কাজ করে না।
বরং যেটির sum সবচেয়ে বেশি, সেটিকেই আগে টার্গেট করে।
তারপর সেই stack-এর top element remove করে এবং sum কমায়।
এরপর আবার নতুন করে তিনটি sum compare করে।
আবার যেটি সবচেয়ে বড় হয়ে যায়, সেটি থেকে element remove করে।
এভাবে প্রতিবার compare ও remove করতে থাকে।
         */
        else if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= st1.top();
            st1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= st2.top();
            st2.pop();
        }
        else
        {
            sum3 -= st3.top();
            st3.pop();
        }
    }
    cout << sum1;

    return 0;
}