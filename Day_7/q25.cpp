#include <iostream>
using namespace std;


int q25(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * q25(n - 1);
    }
}
int main() {
    int n;
    cin>>n;
    cout<<q25(n);
    return 0;
}
