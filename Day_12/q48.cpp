#include <iostream>
using namespace std;

bool q48(int n)
{
    int result = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            result = result + i;
        }
    }
    if (result == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    int n;
     cin>>n;
    if (q48(n))
    {
        cout<<"perfect number";
    }
    else{
        cout<<"Not perfect";
    }    
    return 0;
}