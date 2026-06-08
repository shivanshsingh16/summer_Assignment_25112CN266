#include <iostream>
using namespace std;

bool q46(int n)
{
    int dig = 0, result = 0;
    int temp = n;
    while (temp != 0)
    {
        temp = temp / 10;
        dig++;
    }
    temp = n;
    while (temp != 0)
    {
        int t = 1;
        for (int j = 0; j < dig; j++)
        {
            t = t * (temp % 10);
        }
        result = result + t;
        temp = temp / 10;
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
    if (q46(n))
    {
        cout<<"Armstrong";
    }else{
        cout<<"Not Amstrong";
    }
    return 0;
}