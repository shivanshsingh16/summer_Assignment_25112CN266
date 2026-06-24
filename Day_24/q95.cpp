#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    string word = "", longest = "";

    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == ' ' || i == str.size())
        {
            if (word.size() > longest.size())
            {
                longest = word;
            }
            word = "";
        }
        else
        {
            word = word + str[i];
        }
    }

    cout << longest;

    return 0;
}