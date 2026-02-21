#include <bits/stdc++.h>
// https://www.naukri.com/code360/problems/reverse-first-k-elements-of-queue_982771
using namespace std;
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> tempStk;
    for (int i = 0; i < k; i++)
    {
        tempStk.push(q.front());
        q.pop();
    }
    queue<int> revQueue;
    while (!tempStk.empty())
    {
        revQueue.push(tempStk.top());
        tempStk.pop();
    }
    while (!q.empty())
    {
        revQueue.push(q.front());
        q.pop();
    }

    return revQueue;
};
int main()
{
    queue<int> q;
    int temp;
    while (cin >> temp)
    {
        q.push(temp);
    }
    queue rq = reverseElements(q, 4);
    while (!rq.empty())
    {
        cout << rq.front() << " ";
        rq.pop();
    }

    return 0;
}