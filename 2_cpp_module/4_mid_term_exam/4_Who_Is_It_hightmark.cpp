#include <bits/stdc++.h>

using namespace std;
class Student
{
public:
    int id;
    string name;
    char section;
    int mark;
    Student(int id, string name, char section, int mark)
    {
        this->id = id;
        this->name = name;
        this->section = section;
        this->mark = mark;
    }
};
int main()
{
    int t; // test case
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        Student topper(1000, "empty", 'A', INT_MIN); // OR -20000
        for (int j = 1; j <= 3; j++)
        {
            int id;
            string name;
            char section;
            int mark;
            cin >> id;
            cin >> name;
            cin >> section;
            cin >> mark;

            Student tempStudent(id, name, section, mark);
            if (tempStudent.mark > topper.mark)
            {
                topper = tempStudent;
            }
            else if (tempStudent.mark == topper.mark)
            {
                if (tempStudent.id < topper.id)
                {
                    topper = tempStudent;
                }
            }
        }
        cout << topper.id << " " << topper.name << " " << topper.section << " " << topper.mark << endl;
    }

    return 0;
}

/* // alternative and easy
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    string name;
    char section;
    int mark;
};

int main() {
    int t;
    cin >> t;

    while (t--) {

        Student topper;
        topper.mark = -1; // nobody can get <0
        topper.id = 10000; // বড় id assign for tie-break checking

        for (int i = 0; i < 3; i++) {
            Student s;
            cin >> s.id >> s.name >> s.section >> s.mark;

            if (s.mark > topper.mark) {
                topper = s;
            }
            else if (s.mark == topper.mark && s.id < topper.id) {
                topper = s;
            }
        }

        cout << topper.id << " " << topper.name << " "
             << topper.section << " " << topper.mark << endl;
    }

    return 0;
}

*/