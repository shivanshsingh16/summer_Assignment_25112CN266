#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    while (n2 != 0)
    {
        int t = n2;
        n2 = n1 % n2;
        n1 = t;
    }
    cout << n1;
    return 0;
}
