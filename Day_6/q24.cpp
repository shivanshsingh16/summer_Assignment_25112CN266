#include <iostream>
using namespace std;

int main() {
    int n, p;
    int answer = 1;
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        answer = answer * n;
    }
    cout << answer;
    return 0;
}