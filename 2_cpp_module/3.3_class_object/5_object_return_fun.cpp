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

        this->cls = c;
        this->roll = r;
        this->gpa = g;
    };
};
//! it is only work static object mines direct value pass other setution is not work this best use can use dynamic object
Student fun()
{
    Student karim(6, 32, 4.36);
    return karim;
}

int main()
{

    Student obj = fun();
    cout << obj.cls << ", "
         << obj.roll << ", "
         << obj.gpa << endl;

    return 0;
}
