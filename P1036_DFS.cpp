#include <iostream>
using namespace std;
int element[20];
int ans = 0;
int sum = 0;
int n, k;
bool flag[20];
bool Is_prim(int num)
{
    if (num == 0 && num == 1)
        return false;
    if (num == 2)
        return true;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}
void dfs(int cur, int start)
{
    if (cur == k)
    {
        if (Is_prim(sum))
            ans++;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        if (!flag[i])
        {
            flag[i] = true;
            sum += element[i];
            dfs(cur + 1, i + 1);
            flag[i] = false;
            sum -= element[i];
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> element[i];
    }
    dfs(0, 1);
    cout << ans;
    cout << "\n" << sum;
    return 0;
}