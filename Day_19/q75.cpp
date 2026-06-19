#include <iostream>
using namespace std;

int main() {
        int row, col;
    cin >> row >> col;

    int mat[10][10];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += mat[i][j];
        }
        cout << "Row " << i << ": " << sum << endl;
    }
    return 0;
}
