#include <iostream>
using namespace std;

bool q45(int n)
{
    int k = n, result = 0;
    while (k != 0)
    {
        result = result * 10 + k % 10;
        k = k / 10;
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
    int n;cin>>n;
    if (q45(n))
    {
        cout<<"Palindrome";
    }else{
        cout<<"Not Palindrome";
    }
    
    return 0;
}