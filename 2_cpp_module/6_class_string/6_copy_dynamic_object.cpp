#include <bits/stdc++.h>

using namespace std;
class Cricketer
{
public:
    string county;
    int jerseyNo;
    Cricketer(string country, int jerseyNo)
    {
        this->county = country;
        this->jerseyNo = jerseyNo;
    }
};
int main()
{
    Cricketer *dhoni = new Cricketer("India", 6);
    Cricketer *sakib = new Cricketer("Bangladesh", 20);
    *dhoni = *sakib; // copy dynamic object
    delete sakib;
    cout << dhoni->county << " " << dhoni->jerseyNo << endl;

    return 0;
}