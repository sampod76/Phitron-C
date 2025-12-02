#include <bits/stdc++.h>

using namespace std;
class Student
{
public:
    string name;
    int roll;
    int marks;
};
int main()
{

    /*
      3  --> test case
      sampod nath
      2 89
      aboul nath
      3 79
      poluk nath
      8 60
*/
    int n;
    cin >> n;
    cin.ignore();

    Student a[n];
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, a[i].name); // becaseu name is in have space
        cin >> a[i].roll >> a[i].marks;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }
    /* output
    ampod nath 2 89
    aboul nath 3 79
    poluk nath 8 60
    */
    return 0;
}