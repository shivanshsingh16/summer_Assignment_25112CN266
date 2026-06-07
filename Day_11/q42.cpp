#include <iostream>
using namespace std;


int q42(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    return n2;
}
int main() {
    int n1,n2;
    cin>>n1>>n2;
    cout<<q42(n1,n2);
    return 0;
}