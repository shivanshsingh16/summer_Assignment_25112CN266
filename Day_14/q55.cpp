
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    int target;
    int maxi = INT16_MIN, sec_maxi;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        if (x > maxi)
        {
            sec_maxi = maxi;
            maxi = x;
        }
    }
    cout << sec_maxi;
    return 0;
}