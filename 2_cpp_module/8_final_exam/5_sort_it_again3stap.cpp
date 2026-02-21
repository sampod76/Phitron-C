#include <bits/stdc++.h>

using namespace std;
class Student
{
public:
    string name;
    char section;
    int cls, id, math_marks, eng_marks;
};
bool cam(Student a, Student b)
{

    if (a.eng_marks == b.eng_marks)
    {
        if (a.math_marks == b.math_marks)
        {
            return a.id < b.id;
        }
        else
        {
            return a.math_marks > b.math_marks;
        }
    }
    else
    {
        return a.eng_marks > b.eng_marks;
    }
};
int main()
{
    int n;
    cin >> n;
    Student allStudent[n];
    for (int i = 0; i < n; i++)
    {
        cin >> allStudent[i].name >> allStudent[i].cls >> allStudent[i].section >> allStudent[i].id >> allStudent[i].math_marks >> allStudent[i].eng_marks;
    }
    sort(allStudent, allStudent + n, cam);
    for (int i = 0; i < n; i++)
    {
        cout << allStudent[i].name << " " << allStudent[i].cls << " " << allStudent[i].section << " " << allStudent[i].id << " " << allStudent[i].math_marks << " " << allStudent[i].eng_marks << endl;
    }
    return 0;
}