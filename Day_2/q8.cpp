#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n, result = 0;
    while (k != 0)
    {
        result = result * 10 + k % 10;
        k = k / 10;
    }
    if (result == n)
    {
        cout << "palindrome";
    }
    else
    {
        cout << "not palindrome";
    }
    return 0;
}