#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0;
    int b = 1;
    cout << a << endl
         << b << endl;
    for (int i = 0; i < n - 2; i++)
    {
        int temp = b;
        b = a + b;
        a = temp;
        cout << b << endl;
    }
    return 0;
}