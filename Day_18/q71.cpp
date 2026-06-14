#include <iostream>
using namespace std;

int main()
{
    int row, col;

    cin >> row;
    cin >> col;

    int mat[10][10], trans[10][10];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}