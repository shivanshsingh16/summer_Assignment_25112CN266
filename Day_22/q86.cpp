#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter sentence: ";
    getline(cin, str);

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    cout << "Words:" << count + 1;
    return 0;
}