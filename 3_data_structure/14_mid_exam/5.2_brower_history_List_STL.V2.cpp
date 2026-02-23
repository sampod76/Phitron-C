#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> myList;
    string value;

    // input নেওয়া (end পর্যন্ত)
    while (true)
    {
        cin >> value;
        if (value == "end")
            break;

        myList.push_back(value); // tail এ insert
    }

    int q;
    cin >> q;

    list<string>::iterator tracker = myList.end();
    // শুরুতে tracker invalid রাখলাম

    while (q--)
    {
        string command;
        cin >> command;

        if (command == "visit")
        {
            string target;
            cin >> target;

            auto it = find(myList.begin(), myList.end(), target);

            if (it != myList.end())
            {
                tracker = it;
                cout << *tracker << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }

        else if (command == "next")
        {
            if (tracker != myList.end() && next(tracker) != myList.end())
            {
                tracker++;
                // or// advance(tracker,1);
                // or// tracker=next(tracker) // not change orginal return new
                cout << *tracker << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }

        else if (command == "prev")
        {
            if (tracker != myList.end() && tracker != myList.begin())
            {
                tracker--;
                // or// advance(tracker,-1);
                // or// tracker=prev(tracker) // not change orginal return new
                cout << *tracker << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}