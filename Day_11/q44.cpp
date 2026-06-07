#include <iostream>
using namespace std;

int q44(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}


int main() {
    int n;
    cin>>n;
    cout<<q44(n);
    return 0;
}