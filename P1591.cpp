#include <iostream>
using namespace std;
int res[5000],len;
string Res= "1";
void mul(string a, int b)
{
    int loc = 0, i;
    for (i = 0; i < a.size(); i++)
    {
        res[i] = (a[a.size() - 1 - i] - '0') * b + loc;
        loc = res[i] / 10;
        Res = char(res[i]%10+48) + Res;
    }
    if (loc != 0)
        Res = char(loc+48) + Res;
    len = i;
    while (Res[len] == '0' && len > 0)
        len--;
    for(int j=0,k=len;j<=k;j++,k--)
        swap(res[j],res[k]);
}
int main()
{
    int ans = 0;
    int t, n, m;
    cin >> t >> n >> m;
    while (t--)
    {
        for (int i = 2; i <= n; i++)
        {
            mul(Res,i);
        }
        // for (int j = 0; res[j]; j++)
        // {
        //     if (res[j] - '0' == m)
        //         ans++;
        // }
        // cout << ans << "\n";
        cout << Res;
    }
    return 0;
}