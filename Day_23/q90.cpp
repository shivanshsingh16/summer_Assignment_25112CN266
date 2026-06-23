#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_set<char> seen;

    for (char c : s)
    {
        if (seen.count(c)==1)
        {
            cout << c;
            return 0;
        }
        seen.insert(c);
    }

    cout << "No repeating character";
    return 0;
}