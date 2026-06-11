#include <vector>
#include <iostream>
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
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (arr[i] == 0)
        {
            while (i < j && arr[j] == 0)
            {
                j--;
            }
            swap(arr[i], arr[j]);
            j--;
        }
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}