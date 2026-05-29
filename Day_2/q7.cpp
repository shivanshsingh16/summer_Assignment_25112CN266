#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n;
    int result = 1;
    while (k != 0)
    {
        result = result * (k % 10);
        k = k / 10;
    }
    cout << result;
    return 0;
}