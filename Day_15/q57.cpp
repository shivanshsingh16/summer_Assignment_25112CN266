#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> arr_rev(n);
    for (int i = 0; i < n; i++)
    {
        arr_rev[i] = arr[n -1- i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr_rev[i] << " ";
    }
    return 0;
}