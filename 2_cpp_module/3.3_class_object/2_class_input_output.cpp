#include <bits/stdc++.h>

using namespace std;
/*
input
-----

Sampod chandra
2 4.6
Aksh chandra
3 3.6

*/
class Student
{
public:
    char name[100];
    int roll;
    double gpa;
};
int main()
{
    Student firstStudent, secondStudent;
    cin.getline(firstStudent.name, 100); // when name or string in space that is not work normal cin -> স্পেসসহ string নিতে
    cin >> firstStudent.roll >> firstStudent.gpa;
    cin.ignore(); // ইনপুট buffer এর অতিরিক্ত ENTER clear করতে
    cin.getline(secondStudent.name, 100);
    cin >> secondStudent.roll >> secondStudent.gpa;

    cout
        << firstStudent.name << ", " << firstStudent.roll << ", " << firstStudent.gpa << endl;
    //-------- second student ------
    cout
        << secondStudent.name << ", " << secondStudent.roll << ", " << secondStudent.gpa << endl;

    return 0;
};