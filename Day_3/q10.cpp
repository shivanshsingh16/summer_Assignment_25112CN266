#include <iostream>
using namespace std;

int main() {
        int num;
    cin >> num;
    for (int n = 2; n <= num; n++)
    {
        bool flag = true;
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << n << endl;
        }
    }
    return 0;
}
