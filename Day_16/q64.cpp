#include <iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main() {
    unordered_set<int> st;
        int n;
    cin >> n;
    vector<int> arr;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        st.insert(x);
    }

    for (auto &it : st)
    {
        result.push_back(it);
    }
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}