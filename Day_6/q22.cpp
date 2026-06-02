#include <iostream>
using namespace std;

int main() {
    int n1;
    cin >> n1;
    int n = n1;

    int deci = 0, power = 1;
    while (n > 0)
    {
        deci += (n % 10) * power;
        power *= 2;
        n = n / 10;
    }
    
    cout<< deci << endl;
    return 0;
}
