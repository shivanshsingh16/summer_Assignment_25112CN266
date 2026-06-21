#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int vowels = 0, consonants = 0;

    for (char c : str)
    {
        if (isalpha(c))
        {
            char ch = tolower(c);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    cout << "Vowels = " << vowels << endl;
    cout << "Consonants = " << consonants;

    return 0;
}