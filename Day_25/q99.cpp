#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "enter input number";
    cin >> n;

    string names[n];

    cin.ignore();

    for (int i = 0; i < n; i++)
        getline(cin, names[i]);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (names[j] > names[j + 1])
            {
                swap(names[j], names[j + 1]);
            }
        }
    }

    cout << "Sorted names:\n";

    for (int i = 0; i < n; i++)
        cout << names[i] << endl;

    return 0;
}