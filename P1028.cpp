#include <iostream>
using namespace std;
int f[1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        for (int j = i / 2; j >= 1; j--)
            f[i] += f[j];
        f[i] += 1;
    }
    cout << f[n];
    return 0;
}