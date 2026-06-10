#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    unordered_map<int, int> mpp;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        mpp[x]++;
    }

    for (const auto &pair : mpp)
    {
        if (pair.second > 1)
        {
            cout << pair.first << endl;
        }
    }
    return 0;
}