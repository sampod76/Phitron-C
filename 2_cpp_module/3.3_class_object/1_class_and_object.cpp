#include <bits/stdc++.h>

using namespace std;
class Student
{
public:
    char name[100];
    int roll;
    double gpa;
};
int main()
{
    Student firstStudent; // student class working as a  firstStudent data type
    firstStudent.gpa = 4.2;
    firstStudent.roll = 10;
    char temp[100] = "sampod";
    strcpy(firstStudent.name, temp);
    // or shortcut->  strcpy(firstStudent.name, "sampod");
    cout << firstStudent.name << firstStudent.roll << firstStudent.gpa << endl;

    return 0;
};