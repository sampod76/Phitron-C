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
    int cls; // class
    int roll;
    double gpa;
    Student(int c, int r, double g)
    {
        cls = c;
        roll = r;
        gpa = g;
    }
};
int main()
{
    int c, r;
    double g;
    cin >> c >> r >> g;
    Student firstStudent(c, r, g);

    cout
        << firstStudent.cls << ", " << firstStudent.roll << ", " << firstStudent.gpa << endl;

    return 0;
};

// shortcut --> when you input then not need constructor
/*
class Student
{
public:
    int cls; // class
    int roll;
    double gpa;
};
int main()
{

    Student firstStudent;
    cin >> firstStudent.cls >> firstStudent.roll > firstStudent.gpa;

    cout
        << firstStudent.cls << ", " << firstStudent.roll << ", " << firstStudent.gpa << endl;

    return 0;
};
 */