#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter the size of the matrix:";
    cin >> n;

    int matrix[n][n];
    cout << "enter the matrix elements:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    cout << "Diagonal Sum=" << sum;

    return 0;
}