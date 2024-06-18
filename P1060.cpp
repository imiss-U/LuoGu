#include <iostream>
using namespace std;
int res[30010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int v[30], p[30];
    for (int i = 0; i < m; i++)
    {
        cin >> v[i] >> p[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = n; j >= v[i]; j--)
        {
            res[j] = max(res[j], res[j - v[i]] + v[i] * p[i]);
        }
    }
    cout << res[n];
    return 0;
}