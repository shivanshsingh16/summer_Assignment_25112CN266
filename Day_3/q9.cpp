#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;bool flag=true;
    int fac = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag=false;
            cout << "not prime";
            break;
        }
    }
    if (flag)
    {
        cout << "prime";
    }
    
    return 0;
}