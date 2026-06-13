#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_set<int> unionSet;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        unionSet.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        unionSet.insert(arr2[i]);
    }
    for (auto &tp : unionSet)
    {
        cout << tp << " ";
    }
    return 0;
}