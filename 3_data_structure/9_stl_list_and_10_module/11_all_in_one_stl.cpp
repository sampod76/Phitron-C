#include <iostream>
#include <list>
#include <algorithm> // find, count etc.
using namespace std;

// 🔹 Print function (const reference ব্যবহার করছি, copy হবে না)
void printList(const list<int> &l, string msg)
{
     cout << msg << " : ";
     for (int x : l)
          cout << x << " ";
     cout << endl
          << endl;
}

int main()
{
     // ===============================
     // 1️⃣ Constructor & Initialize
     // ===============================
     list<int> l1 = {3, 1, 4, 1, 5};
     printList(l1, "Initial List");

     // ===============================
     // 2️⃣ push / emplace
     // ===============================
     l1.push_back(9);       // শেষে যোগ
     l1.push_front(2);      // সামনে যোগ
     l1.emplace_back(100);  // object বানিয়ে শেষে যোগ
     l1.emplace_front(200); // object বানিয়ে সামনে যোগ
     printList(l1, "After push & emplace");

     // ===============================
     // 3️⃣ front / back
     // ===============================
     cout << "Front: " << l1.front() << endl;
     cout << "Back : " << l1.back() << endl
          << endl;

     // ===============================
     // 4️⃣ Iterator movement
     // ===============================
     auto it = l1.begin(); // প্রথম element
     advance(it, 2);       // ২ ঘর সামনে

     cout << "Iterator at position 2: " << *it << endl;

     it++; // সামনে
     it--; // পেছনে

     cout << "After move: " << *it << endl
          << endl;
     // ===============================
     // 4️⃣ distance checker
     // ===============================
     list<int> l5 = {10, 20, 30, 40, 50};

     auto it1 = l5.begin(); // 10
     auto it2 = l5.end();

     cout << distance(it1, it2); // 5
     // ===============================
     // 5️⃣ Insert / Erase
     // ===============================
     l1.insert(it, 555); // নির্দিষ্ট জায়গায় insert
     printList(l1, "After insert");

     l1.erase(it); // ওই জায়গার element delete
     printList(l1, "After erase");

     // ===============================
     // 6️⃣ Update value at position
     // ===============================
     auto repIt = next(l1.begin(), 3);
     *repIt = 999; // value replace
     printList(l1, "After replace at index 3");

     // ===============================
     // 7️⃣ remove / remove_if
     // ===============================
     l1.remove(1); // সব 1 delete
     printList(l1, "After remove(1)");

     l1.remove_if([](int x)
                  { return x > 500; });
     // 500 এর বেশি সব delete
     printList(l1, "After remove_if (>500)");

     // ===============================
     // 8️⃣ sort / reverse / unique
     // ===============================
     l1.sort(); // ascending sort
     printList(l1, "After sort");

     l1.reverse(); // reverse
     printList(l1, "After reverse");

     l1.sort();
     l1.unique(); // consecutive duplicate remove
     printList(l1, "After unique");

     // ===============================
     // 9️⃣ find / count (algorithm)
     // ===============================
     auto findIt = find(l1.begin(), l1.end(), 4);
     if (findIt != l1.end())
          cout << "4 Found" << endl
               << endl;

     cout << "Count of 3: "
          << count(l1.begin(), l1.end(), 3) << endl
          << endl;

     // ===============================
     // 🔟 merge
     // ===============================
     list<int> l2 = {10, 20, 30};
     l1.sort();
     l2.sort();

     l1.merge(l2); // l2 empty হবে
     printList(l1, "After merge");

     // ===============================
     // 1️⃣1️⃣ splice
     // ===============================
     list<int> l3 = {1000, 2000};
     l1.splice(l1.begin(), l3); // l3 move হয়ে যাবে
     printList(l1, "After splice");

     // ===============================
     // 1️⃣2️⃣ Reverse Iterator
     // ===============================
     cout << "Reverse Traversal: ";
     for (auto rit = l1.rbegin(); rit != l1.rend(); rit++)
          cout << *rit << " ";
     cout << endl
          << endl;

     // ===============================
     // 1️⃣3️⃣ size / empty / resize
     // ===============================
     cout << "Size: " << l1.size() << endl;
     cout << "Empty? " << (l1.empty() ? "Yes" : "No") << endl;

     l1.resize(5); // size কমালে extra delete
     printList(l1, "After resize(5)");

     // ===============================
     // 1️⃣4️⃣ clear
     // ===============================
     l1.clear();
     printList(l1, "After clear");

     return 0;
}
