#include <bits/stdc++.h>
using namespace std;

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

int main()
{

    Student rahim(6, 21, 2.5);
    Student *karim = new Student(7, 50, 2.30); // dynamic objet return a pointer
    cout << rahim.cls << ", "
         << rahim.roll << ", "
         << rahim.gpa << endl;
    cout << karim->cls << ", "
         << karim->roll << ", "
         << karim->gpa << endl;

    return 0;
}
