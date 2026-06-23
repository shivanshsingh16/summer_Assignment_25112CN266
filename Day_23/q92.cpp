#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> freq;

    for (char c : s)
        freq[c]++;

    char maxChar;
    int maxFreq = 0;

    for (auto it : freq)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            maxChar = it.first;
        }
    }

    cout << maxChar;
    return 0;
}