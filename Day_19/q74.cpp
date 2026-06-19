#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mat[10][10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    bool isSym = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                isSym = false;
                break;
            }
        }
        if (!isSym)
        {
            break;
        }
    }
    cout << endl;
    if (isSym)
    {
        cout << "SYMMETRIC" << endl;
    }
    else
    {
        cout << "NOT SYMMETRIC" << endl;
    }
    return 0;
}
