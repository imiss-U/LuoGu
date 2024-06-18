#include <iostream>
using namespace std;
long long f[21][21][21];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            for (int k = 0; k <= 20; k++)
            {
                if (i * j * k == 0)
                    f[i][j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            for (int k = 1; k <= 20; k++)
            {
                if (i < j && j < k)
                {
                    f[i][j][k] = f[i][j][k - 1] + f[i][j - 1][k - 1] - f[i][j - 1][k];
                }
                else
                {
                    f[i][j][k] = f[i - 1][j][k] + f[i - 1][j - 1][k] + f[i - 1][j][k - 1] - f[i - 1][j - 1][k - 1];
                }
            }
        }
    }
    long long a = 0, b = 0, c = 0;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        else
        {
            if (a <= 0 || b <= 0 || c <= 0)
                cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
            else
            {
                if (a > 20)
                    cout << "w(" << a << ", " << b << ", " << c << ") = " << f[20][20][20] << "\n";
                else if (b > 20)
                    cout << "w(" << a << ", " << b << ", " << c << ") = " << f[20][20][20] << "\n";
                else if (c > 20)
                    cout << "w(" << a << ", " << b << ", " << c << ") = " << f[20][20][20] << "\n";
                else
                    cout << "w(" << a << ", " << b << ", " << c << ") = " << f[a][b][c] << "\n";
            }
        }
    }
    return 0;
}