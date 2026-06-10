#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int target;
    int freq = 0;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "enter the target" << endl;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            freq++;
        }
    }
    cout << freq;
    return 0;
}