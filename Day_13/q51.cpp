#include <iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    int mini = INT16_MAX;
    int maxi = INT16_MIN;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        if (x < mini)
        {
            mini = x;
        }
        if (x > maxi)
        {
            maxi = x;
        }
    }
    cout << "the maximum is :" << maxi << endl;
    cout << "the minimum is :" << mini << endl;
    return 0;
}