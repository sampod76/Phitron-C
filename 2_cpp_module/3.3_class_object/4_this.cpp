#include <bits/stdc++.h>
using namespace std;

/*
input
-----
5 2 4.6
6 1 4.9
*/

class Student
{
public:
    int cls;    // class number
    int roll;   // roll number
    double gpa; // grade

    Student(int c, int r, double g)
    {
        // ⚠️ C++ এ this একটি pointer
        // তাই this->property লিখতে হয়।
        // this.cls লিখলে error হবে।

        // কারণ:
        // this এর datatype হলো: Student*  (Student pointer)
        // কিন্তু dot(.) অপারেটর ব্যবহার হয় object এর সাথে, pointer এর সাথে নয়।

        // তাই pointer এর property access করার নিয়ম:
        // 1) (*this).cls  ← dereference করে access
        // 2) this->cls     ← shortcut (arrow operator)

        this->cls = c;  // সঠিক
        this->roll = r; // সঠিক
        this->gpa = g;  // সঠিক

        // ❌ this.cls = c; (এটা ভুল, কারণ this pointer)
        // ❌ this.roll = r;

        // নিচের লাইনগুলোও একই কাজ করে:
        // (*this).cls = c;
        // (*this).roll = r;
        // (*this).gpa = g;
    }
};

int main()
{
    int c, r;
    double g;
    cin >> c >> r >> g;

    Student firstStudent(c, r, g);

    cout << firstStudent.cls << ", "
         << firstStudent.roll << ", "
         << firstStudent.gpa << endl;

    return 0;
}
