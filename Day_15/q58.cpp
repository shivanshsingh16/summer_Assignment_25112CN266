#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        swap(arr[i], arr[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}