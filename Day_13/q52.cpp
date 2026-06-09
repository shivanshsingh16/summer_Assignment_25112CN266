#include <iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int even = 0, odd = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        if (x % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    cout << "odd numbers are :" << odd << endl;
    cout << "even numbers are :" << even << endl;
    return 0;
}