#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n;
    int result = 1;
    while (k > 1)
    {
        result = result * k;
        k--;
    }
    cout << result;

    return 0;
}