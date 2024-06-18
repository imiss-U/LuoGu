// # 又又又又又是抄的题解………………………………
#include <iostream>
using namespace std;
int f[20010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int V, n;
    int v[25];
    cin >> V >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        for (int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + v[i]);
    cout <<V- f[V];
    return 0;
}