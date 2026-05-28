#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n;
    int cnt = 0;
    while (k != 0)
    {
        k = k / 10;
        cnt++;
    }
    cout << cnt;
    return 0;
}