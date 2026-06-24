#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        int count = 1;
        
        while (i < str.size() - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        cout << str[i] << count;
    }

    return 0;
}