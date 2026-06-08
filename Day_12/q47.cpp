#include <iostream>
using namespace std;


int q47(int nth)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < nth - 2; i++)
    {
        int temp = b;
        b = a + b;
        a = temp;
    }
    if (nth == 1)
    {
        return 0;
    }
    else
    {
        return b;
    }
}


int main() {
        int n;cin>>n;
    cout<<q47(n);
    return 0;
}
