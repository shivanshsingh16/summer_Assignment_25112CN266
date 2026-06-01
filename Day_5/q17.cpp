#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            result = result + i;
        }
    }
    if (result == n)
    {
        cout << "perfect number";
    }
    else
    {
        cout << "not a perfect number";
    }
    return 0;
}