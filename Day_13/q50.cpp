#include <iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        sum = sum + x;
    }
    cout << "the sum is :" << sum<<endl;
    cout << "the average is :" << sum / n;
    return 0;
}