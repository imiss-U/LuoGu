#include <iostream>
using namespace std;
int res[10000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int s, n, d;
    cin >> s >> n >> d;
    s /= 10;
    int c[11], w[11];
    for (int i = 0; i < d; i++)
    {
        cin >> c[i] >> w[i];
        c[i] /= 10;
        w[i] /= 10;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = c[i]; j <= s; j++)
            {
                res[j] = max(res[j], res[j - c[i]] + w[i]);
            }
        }
        s += res[s];
    }
    cout << s * 10;
    return 0;
}