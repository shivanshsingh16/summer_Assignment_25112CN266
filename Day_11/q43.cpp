#include <iostream>
using namespace std;

bool q43(int n)
{
    int fac = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin>>n;
    if (q43(n))
    {
        cout<<"prime";
    }
    else{
        cout<<"not prime";
    }
    
    return 0;
}
