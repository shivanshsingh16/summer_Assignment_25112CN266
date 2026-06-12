#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum = sum + x;
        arr.push_back(x);
    }
    cout << "The missing number:" << ((n + 1) * (n + 2)) / 2 - sum;
    return 0;
}