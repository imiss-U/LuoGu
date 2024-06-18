#include <iostream>
using namespace std;
int square[510][510], temp[510][510];
int n;
void Create(int n)
{
    int u = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            square[i][j] = u++;
        }
    }
}
void Operate(int x, int y, int r, int z)
{
    if (z == 0)
    {
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                temp[x - y + j][x + y - i] = square[i][j];
            }
        }
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                square[i][j] = temp[i][j];
            }
        }
    }
    else
    {
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                temp[x + y - j][y - x + i] = square[i][j];
            }
        }
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                square[i][j] = temp[i][j];
            }
        }
    }
}
void Show()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << square[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int m;
    cin >> n >> m;
    Create(n);
    for (int k = 0; k < m; k++)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        Operate(x, y, r, z);
    }
    Show();
    return 0;
}