#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string result = "";

    for (int i = 0; i < str.size(); i++)
    {
        bool found = false;

        for (int j = 0; j < result.size(); j++)
        {
            if (str[i] == result[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            result = result + str[i];
        }
    }

    cout << result;

    return 0;
}