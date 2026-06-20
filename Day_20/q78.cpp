#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the matrix: ";
    cin >> n;

    int A[n][n];

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    bool Symmetric = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                Symmetric = false;
                break;
            }
        }
        if (!Symmetric) break;
    }

    if (Symmetric)
        cout << "Matrix is ymmetric";
    else
        cout << "Matrix is NOT Symmetric";

    return 0;
}