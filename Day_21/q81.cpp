#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int length = 0;
    for (char c : str)
    {
        length++;
    }

    cout << "Length= " << length;
    return 0;
}