#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            bool check = true;
            for (int j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                result = i;
            }
        }
    }
    cout << result;
    return 0;
}
