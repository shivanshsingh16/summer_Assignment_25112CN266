#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    vector<int> arr3(n+m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr3[i + n] = arr2[i];
    }
    for (int i = 0; i < arr3.size(); i++)
    {
        cout<<arr3[i];
    }
    
    return 0;
}