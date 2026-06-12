#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
        int result = -1;
    unordered_map<int, int> mpp;
    int test = INT16_MIN;
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        mpp[x]++;
    }

    for (auto &p : mpp)
    {
        if (p.second > test)
        {
            result = p.first;
            test = p.second;
        }
    }
    cout <<"The element with max frequency is:" <<result;
    return 0;
}