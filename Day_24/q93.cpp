#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size())
    {
        cout << "Not rotation";
    }
    else
    {
        string temp = s1 + s1;

        if (temp.find(s2) != -1)
            cout << "Rotation";
        else
            cout << "Not rotation";
    }

    return 0;
}