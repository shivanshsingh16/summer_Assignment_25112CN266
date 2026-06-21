#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter the string:";
    cin >> str;

    int n = str.length();
    for (int i = n - 1; i >= 0; i--)
    {
        cout << str[i];
    }

    return 0;
}