#include <iostream>
using namespace std;
int res[10];
bool visit[10];
void dfs(int cur, int all)
{
    if (cur == all)
    {
        for (int i = 0; i < all; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    for (int i = 1; i <= all; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            res[cur] = i;
            dfs(cur + 1, all);
            visit[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int f[10];
    for (int i = 1; i <= n; i++)
        f[i] = i;
    dfs(0, n);
    return 0;
}