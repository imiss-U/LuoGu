// # 又是抄的题解…………
#include <iostream>
using namespace std;
int f[20][20];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        f[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= 1)
                f[j][i] = f[j - 1][i] + f[j + 1][i - 1];
            if (j == 0)
                f[j][i] = f[j + 1][i - 1];
        }
    }
    cout << f[0][n];
    return 0;
}