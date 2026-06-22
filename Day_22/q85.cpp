#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cout << "Enter string: ";
    cin >> str;

    string rev = str;
    reverse(rev.begin(), rev.end());

    if (str == rev)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}