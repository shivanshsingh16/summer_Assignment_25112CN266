#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n;
    int cnt = 0;
    while (k>0)
    {
        if ((k & 1))
        {
            cnt++;
        }
        k=k >> 1;
    }
    cout << cnt;
    return 0;
}