#include <bits/stdc++.h>

using namespace std;
class Student
{
public:
    string name;
    char section;
    int cls, id;
};
int main()
{
    int n;
    cin >> n;
    Student allStudent[n];
    char sectionStore[n];
    for (int i = 0; i < n; i++)
    {
        cin >> allStudent[i].name >> allStudent[i].cls >> allStudent[i].section >> allStudent[i].id;
        sectionStore[i] = allStudent[i].section;
    }
    reverse(sectionStore, sectionStore + n);

    for (int i = 0; i < n; i++)
    {
        cout << allStudent[i].name
             << " " << allStudent[i].cls << " " << sectionStore[i] << " " << allStudent[i].id << endl;
    }
    return 0;
}