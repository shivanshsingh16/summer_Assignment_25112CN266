#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n;
    int result = 0;
    while (k != 0)
    {
        int dig = k % 10;
        int r = 1;
        for (int i = 1; i <= dig; i++)
        {
            r = r * i;
        }
        result = result + r;
        k = k / 10;
    }
    if (result == n)
    {
        cout << "strong number";
    }
    else
    {
        cout << "not strong number";
    }
    return 0;
}
