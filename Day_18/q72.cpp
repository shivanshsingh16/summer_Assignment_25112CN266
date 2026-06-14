#include <iostream>
using namespace std;

int main()
{
    int row;
    int answer = 0;

    cin >> row;

    int mat[10][10];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        answer = answer + mat[i][i];
    }
    cout << answer;
}
