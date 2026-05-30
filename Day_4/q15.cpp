#include <iostream>
using namespace std;

int main() {
        int n;
    cin >> n;
    int dig = 0, result = 0;
    int temp = n;
    while (temp != 0)
    {
        temp = temp / 10;
        dig++;
    }
    temp = n;
    while (temp != 0)
    {
        int t = 1;
        for (int j = 0; j < dig; j++)
        {
            t = t * (temp % 10);
        }
        result = result + t;
        temp = temp / 10;
    }
    if (result == n)
    {
        cout << "Armstrong";
    }
    else
    {
        cout << "not armstrong";
    }
    return 0;
}